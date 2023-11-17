import os
def forever():
    pid = os.getpid()
    num = 1
    printNum = int(pid)
    while num:
        print("pid_" + str(num) + " forever " + str(printNum))
        num += 1
        printNum = int(pid) * num

forever()

