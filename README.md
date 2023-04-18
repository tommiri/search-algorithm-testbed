# Search algorithm testbed

A testbed for sequential and binary search algorithms for contiguous lists made with C++. For predictability reasons, for searches the testbed always uses lists of user-defined length filled with odd values. The performance run uses random list lengths and target values. This project was made as the final project for TAMK's Data Structures and Algorithms course.

## Run Locally

Clone the project

```bash
  git clone https://github.com/tommiri/search-algorithm-testbed.git
```

Go to the project directory

```bash
  cd search-algorithm-testbed
```

Compile the source files with g++ or another compiler of your choice

```bash
  g++ src/*.cpp -o search_testbed
```

Run the program

```bash
  ./search_testbed
```

## Usage/Examples

The main menu of the program allows you to choose which algorithm you would like to test, or you can choose to do a performance run, comparing the performance of the two search algorithms over a user given amount of repetitions.
<img src="https://i.imgur.com/D8fIfSZ.png" />
<br><br>
After choosing an option, answer the given prompts and the program will run, displaying results at the end. The following is an example of the summary after running a performance run with 500 repetitions.
<img src="https://i.imgur.com/FydbUB2.png" />

## Acknowledgements

A good amount of the project's code was supplied in our course's book "Data Structures and Program Design In C++" by Robert L. Kruse.

[Find it on Amazon](https://www.amazon.com/Structures-Program-Design-Robert-1998-10-03/dp/B01JXQSJH2)
