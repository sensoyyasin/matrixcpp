import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector
from Matrix import Matrix


def main():
    u = Matrix([
		[1., 0.],
        [0., 1.],
	])
    print(u.trace()) # 2.0

    u = Matrix([
		[2., -5., 0.],
        [4., 3., 7.],
        [-2., 3., 4.]
	])
    print(u.trace()) # 9.0

    u = Matrix([
		[-2., -8., 4.],
        [1., -23., 4.],
        [0., 6., 4.]
	])
    print(u.trace()) # -21


if __name__ == "__main__":
    main()
