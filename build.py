import os
import sys
import argparse
import shutil
import re
from subprocess import call
from subprocess import check_output


def which2(program):

    def is_exe(file_path):
        return os.path.isfile(file_path) and os.access(file_path, os.X_OK)

    if os.name == "nt":
        program += ".exe"
    fpath, fname = os.path.split(program)
    if fpath:
        if is_exe(program):
            return program
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            path = path.strip('"')
            exe_file = os.path.join(path, program)
            if is_exe(exe_file):
                return exe_file

    return None


def which(cmd):
    if sys.version_info >= (3, 3):
        return shutil.which(cmd)
    else:
        return which2(cmd)  # fall-back 'which' function for Python 2.x (see http://stackoverflow.com/a/377028)


def init_args():
    parser = argparse.ArgumentParser(description='Builds QtCryptoHash')
    parser.add_argument("-a", "--arch",
                        choices=["x64", "x86"],
                        default="x64",
                        help="target architecture (default: x64)")
    parser.add_argument("-d", "--debug",
                        action='store_true',
                        help="compiles with debug symbols")
    parser.add_argument("-s", "--static",
                        action='store_true',
                        help="compiles as static library")
    return parser.parse_args()


def main():
    args = init_args()
    if os.path.isdir("build"):
        shutil.rmtree("build", ignore_errors=True)

    if which("qmake") is None:
        print("'qt' not found in path!")
        return

    if os.name == "nt":
        spec = check_output(["qmake", "-query", "QMAKE_SPEC"]).strip()
        pattern = re.compile(b"^win(.*)msvc([0-9]{4})$")
        if pattern.match(spec) or spec == "win32-icc":
            make_cmd = "nmake"
        else:
            make_cmd = "mingw32-make"
    else:
        make_cmd = "make"

    if which(make_cmd) is None:
        print("'" + make_cmd + "' not found in path!")
        return

    build_path = "build/" + args.arch + "/" + ("static" if args.static else "dynamic") + "/"
    build_config = (" debug_and_release" if os.name == "posix" else "") + (" static" if args.static else "")
    build_config = ("\"CONFIG +=" + build_config + "\" " if len(build_config) else "")
    call("qmake " + build_config + "-o \"" + build_path + "Makefile\"", shell=True)
    os.chdir(build_path)
    call(make_cmd + " " + ("debug" if args.debug else "release"), shell=True)


if __name__ == '__main__':
    main()

