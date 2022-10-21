from functools import lru_cache
from importlib.resources import path
from mmap import mmap
from os import pathsep
import string
from typing import List
import numpy as np

a = [[0]] * 2
b = "v"
a[0].append(9)
print(a)
