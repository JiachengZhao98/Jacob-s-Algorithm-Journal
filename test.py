from functools import lru_cache
from importlib.resources import path
from logging import root
from mmap import mmap
from os import pathsep
import string
from typing import List
import numpy as np
import math
from numpy import roots
import numpy
from collections import deque


a = deque([1])
a.appendleft(2)
print(a[1])


def uniquePaths(n: int) -> int:
    
