import sys

with open(sys.argv[1]) as compile_commands_file:
    content = compile_commands_file.read()
    contentList = list(content)
    del contentList[-3]
    content = "".join(contentList)

with open(sys.argv[1], "w") as compile_commands_file:
    compile_commands_file.write(content)