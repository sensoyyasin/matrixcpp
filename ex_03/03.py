import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector
from Matrix import Matrix


def main():
    u = Vector([0., 0.])
    v = Vector([1., 1.])
    print(u.dot(v)) #0.0

    u = Vector([1., 1.])
    v = Vector([1., 1.])
    print(u.dot(v)) #2.0

    u = Vector([-1., 6.])
    v = Vector([3., 2.])
    print(u.dot(v)) #9.0



if __name__ == "__main__":
    main()
