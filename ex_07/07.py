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
    v = Vector([4., 2.])
    print(u.mul_vec(v)) # [4.] # [2.]

    u = Matrix([
		[2., 0.],
        [0., 2.],
	])
    v = Vector([4., 2.])
    print(u.mul_vec(v)) # [8.] # [4.]

    u = Matrix([
		[2., -2.],
        [-2., 2.],
	])
    v = Vector([4., 2.])
    print(u.mul_vec(v)) # [4.] # [-4.]

    u = Matrix([
		[1., 0.],
        [0., 1.],
	])

    v = Matrix([
		[1., 0.],
        [0., 1.],
	])

    print(u.mul_mat(v)) # [1., 0.], #[0., 1.]


if __name__ == "__main__":
    main()
