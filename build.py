import os
import sys
import argparse
import shutil
from subprocess import call


def which2(program):

    def is_exe(file_path):
        return os.path.isfile(file_path) and os.access(file_path, os.X_OK)

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
    parser.add_argument("-c", "--compiler",
                        choices=["msvc", "mingw"],
                        default="msvc",
                        help="compiler to be used (default: msvc)")
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

    if args.compiler == "msvc" and which("nmake.exe") is None:
        print("msvc missing from path!")
        return

    if args.compiler == "mingw" and which("mingw32-make.exe") is None:
        print("mingw missing from path!")
        return

    if which("qmake.exe") is None:
        print("qt missing from path!")
        return

    build_path = "build/" + args.arch + "/" + ("static" if args.static else "dynamic") + "/"
    call("qmake" + (" \"CONFIG += static\" " if args.static else " ") + "-o \"" + build_path + "Makefile\"")
    os.chdir(build_path)
    call("nmake " + ("debug" if args.debug else "release"))


if __name__ == '__main__':
    main()
