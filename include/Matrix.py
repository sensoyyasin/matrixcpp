class Matrix:
    def __init__(self, rows_list):
        self.data = []
        for row in rows_list:
            new_row = []
            for element in row:
                new_row.append(float(element))
            self.data.append(new_row)

        self.rows = len(self.data)
        self.cols = len(self.data[0])


    def add(self, v):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] += v.data[i][j]

    def sub(self, v):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] -= v.data[i][j]

    def scl(self, a):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] *= a

    def __str__(self):
        lines = []
        for row in self.data:
            parts = []
            for element in row:
                parts.append(str(element))
            lines.append("[" + ", ".join(parts) + "]")
        return "\n".join(lines)
