import subprocess

filename = 'forever.py'
while True:
    p = subprocess.Popen('python3 '+filename, shell=True).wait()
    if p != 0:
        continue
    else:
        break
