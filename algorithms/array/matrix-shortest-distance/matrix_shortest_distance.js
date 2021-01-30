// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

const matrix = [
    [1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
    [1, 0, 1, 0, 1, 1, 1, 0, 1, 1 ],
    [1, 1, 1, 0, 1, 1, 0, 1, 0, 1 ],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ],
    [1, 1, 1, 0, 1, 1, 1, 0, 1, 0 ],
    [1, 0, 1, 1, 1, 1, 0, 1, 0, 0 ],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 1 ],
    [1, 0, 1, 1, 1, 1, 0, 1, 1, 1 ],
    [1, 1, 0, 0, 0, 0, 1, 0, 0, 1 ]
];

const src = { y: 0, x: 0 };
const dest = { y: 3, x: 4 };

// check whether given cell (row, col) is a valid
// cell or not.
const isValid = (row, col) => {
    // return true if row number and column number
    // is in range
    return (
        row >= 0 &&
        row < matrix.length &&
        col >= 0 &&
        col < matrix[0].length
    );
};

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
const rowNum = [-1, 0, 0, 1];
const colNum = [0, -1, 1, 0];

const BFS = (matrix, src, dest) => {
    // check source and destination cell
    // of the matrix have value 1
    if (!matrix[src.y][src.x] || !matrix[dest.y][dest.x]) return -1;

    let visited = [];
    for (let y = 0; y < matrix.length; y++) {
        visited[y] = [];

        for (let x = 0; x < matrix[0].length; x++) {
            visited[y][x] = null;
        }
    }

    // Mark the source cell as visited
    visited[src.y][src.x] = true;

    const q = [
        [src, 0]
    ];

    while (q.length) {
        const [cell, distance] = q.pop();

        if (cell.y === dest.y && cell.x == dest.x) return distance;

        for (let i = 0; i < 4; i++) {
            const row = cell.y + rowNum[i];
            const col = cell.x + colNum[i];

            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && matrix[row][col] && !visited[row][col]) {
                visited[row][col] = true;
                q.unshift([{y: row, x: col}, distance + 1]);
            }
        }
    }

    return -1;
};

console.log(
    BFS(matrix, src, dest)
);

