import os
import sys
import subprocess

TEMPLATE = '''#include "../tools.h"

int main(int argc, char const *argv[]) {
    return 0;
}
'''

SRC_DIR = './Leetcode'
BUILD_DIR = 'build'

def create_cpp_file(qid):
    filename = f'{qid}.cpp'
    filepath = os.path.join(SRC_DIR, filename)
    if os.path.exists(filepath):
        print(f"[!] File already exists: {filename}")
        return False
    with open(filepath, 'w') as f:
        f.write(TEMPLATE)
    print(f"[+] Created {filename}")

    # 自动在右侧窗口打开
    subprocess.run(["code", "--reuse-window", filepath])
    return True

def configure():
    print("[*] Configuring CMake...")
    subprocess.run(['cmake', '-S', '.', '-B', BUILD_DIR], check=True)

def build(qid):
    print(f"[*] Building Leetcode-{qid}...")
    subprocess.run(['cmake', '--build', BUILD_DIR, '--target', f'Leetcode-{qid}'], check=True)

def run(qid):
    exe_path = os.path.join(BUILD_DIR, f'Leetcode-{qid}')
    if os.name == 'nt':
        exe_path += '.exe'
    print(f"[*] Running {exe_path}...")
    subprocess.run([exe_path], check=True)

def main():
    if len(sys.argv) < 2:
        # print("Usage: lc.py [new|build|run|all] <qid>")
        print("Usage: lc.py <qid>")
        return

    # command = sys.argv[1]
    # qid = sys.argv[2]
    qid = sys.argv[1]

    created = create_cpp_file(qid)
    if created:
        configure()
    # if command == 'new':
    #     created = create_cpp_file(qid)
    #     if created:
    #         configure()
    # elif command == 'build':
    #     build(qid)
    # elif command == 'run':
    #     run(qid)
    # elif command == 'all':
    #     created = create_cpp_file(qid)
    #     configure()
    #     build(qid)
    #     run(qid)
    # else:
    #     print(f"[!] Unknown command: {command}")

if __name__ == '__main__':
    main()
