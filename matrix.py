def input_matrix(rows, cols, name):
    print(f"\nEnter elements for {name} ({rows}x{cols}):")
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Row {i+1}: ").split()))
        matrix.append(row)
    return matrix

def add_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[0])):
            row.append(A[i][j] + B[i][j])
        result.append(row)
    return result

def multiply_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(B[0])):
            sum = 0
            for k in range(len(B)):
                sum += A[i][k] * B[k][j]
            row.append(sum)
        result.append(row)
    return result

def print_matrix(matrix, name):
    print(f"\n{name}:")
    for row in matrix:
        print(' '.join(map(str, row)))

def main():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))

    A = input_matrix(rows, cols, "Matrix A")
    B = input_matrix(rows, cols, "Matrix B")

    sum_matrix = add_matrices(A, B)
    product_matrix = multiply_matrices(A, B)

    print_matrix(A, "Matrix A")
    print_matrix(B, "Matrix B")
    print_matrix(sum_matrix, "Sum of A and B")
    print_matrix(product_matrix, "Product of A and B")

if __name__ == "__main__":
    main()
