import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector
from Matrix import Matrix


def main():
    u = Vector([2., 3.])
    v = Vector([5., 7.])
    u.add(v)
    print(u)
    # [7.0]
    # [10.0]

    u = Vector([2., 3.])
    v = Vector([5., 7.])
    u.sub(v)
    print(u)
    # [-3.0]
    # [-4.0]

    u = Vector([2., 3.])
    u.scl(2.)
    print(u)
    # [4.0]
    # [6.0]

    u = Matrix([[1., 2.], [3., 4.]])
    v = Matrix([[7., 4.], [-2., 2.]])
    u.add(v)
    print(u)
    # [8.0, 6.0]
    # [1.0, 6.0]

    u = Matrix([[1., 2.], [3., 4.]])
    v = Matrix([[7., 4.], [-2., 2.]])
    u.sub(v)
    print(u)
    # [-6.0, -2.0]
    # [5.0, 2.0]

    u = Matrix([[1., 2.], [3., 4.]])
    u.scl(2.)
    print(u)
    # [2.0, 4.0]
    # [6.0, 8.0]


if __name__ == "__main__":
    main()
