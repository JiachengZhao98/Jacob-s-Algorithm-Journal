from typing import List, Type
import string

def findString(words: List[str]) -> int:
    my_suffix = {}
    for i in range(len(words[0])):
        my_suffix.append(words[0][i:])

    for i in range(1, len(words)):

