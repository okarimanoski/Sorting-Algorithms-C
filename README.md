# Assingment: Sorting Algorithms

## Description
The goal of this assignment is to implement a program that provides various sorting algorithms for integers and strings.
The focus of this assignment is merely on the implementation of the algorithms, not at all on their performance.

## Program Sequence
In the following, a complete run of the program is described.

### Command Line Arguments
The program is started with the following command line arguments:
`./a2 <algorithm> <datatype> <count> <list>`

Everything between `<` and `>` is a placeholder with the following meaning:

| Parameter   | Valid Arguments                                                   | Meaning                             | 
|-------------|-------------------------------------------------------------------|-------------------------------------|
| `algortihm` | `bubble`, `merge`, `heap`                                         | The algorithm to sort with          |
| `datatype`  | `int`, `string`                                                   | The type of the data                |
| `count`     | Any integer                                                       | The number of elements in the array |
| `list`      | Data of the correct type, separated by ',' (no spaces in-between) | The array to sort                   |

### Error Messages and Exit Codes
When parsing the command line arguments, the following errors must be detected and handled:

| Exit Code | Error Message                                       | Error to detect                                                                     |
|-----------|-----------------------------------------------------|-------------------------------------------------------------------------------------|
| 1         | `"Usage: ./a2 <algorithm> <type> <count> <data>\n"` | Incorrect number of arguments provided                                              |
| 2         | `Invalid sorting algorithm!\n`                      | The argument for the sorting algorithm is none of those specified above             |
| 3         | `Invalid data type!\n`                              | The argument for the data type is none of those specified above                     |
| 4         | `Element count is not an integer!\n`                | The argument for count is not an integer, i.e., contains other symbols              |
| 5         | `Invalid element count!\n`                          | The argument for count is smaller than 1                                            |
| 6         | `Not enough elements given!\n`                      | The array contains less than `<count>` elements                                     |
| 7         | `Too many elements given!\n`                        | The array contains more than `<count>` elements                                     |
 

Other errors, which are not mentioned here, do not have to be detected or handle; you may assume they will never occur.
If an exit code is specified, the program should terminate with that return value. After a successful run without any
errors, the program should return 0.

### Program Sequence
First, the array is printed, followed by the start message.
```
[3, 1, 2]
--- Start sorting ---
```
Then, the sorting algorithm is invoked. Finally, the finish message and the array are printed again.
```
--- Finish sorting ---
[1, 2, 3]
```
The program accepts no input while it is running, therefore, there is also no command prompt or similar.

#### Printing the array
The array is always printed the following way, regardless of the datatype of its contens: First, an opening bracket
('[') is printed. Then follow the elements of the array, separated by a comma and a space. Finally, a closing
bracket is printed, usually followed by a newline (unless stated otherwise). See also the examples below.

```
[1, 2, 3]
[C, is, fun]
```
This way of printing the array is also referred to in the algorithm definintions in the next section.

#### Ordering elements
In order to be sortable, elements need to have a defined order. For integers, we simply use their numeric order. For
strings, we use the same method as a dictionary usually does, i.e., by the first character, then by the second, and
so on. However, we order characters differently than usual: We use the order in the [ASCII table](https://www.asciitable.com/)
to determine which character comes first. Smaller ASCII values come before larger ones. 

### Algorithms
In the following, the algorithms to implement are defined. **Follow these definitions as closely as possible.** Do not
implement any optimizations or similar, as the test cases will not pass if you do that! The same goes for the point
in the algorithm where the array is printed, as its content may be in a different order if you do not precisely
follow the instructions.

The algorithms are specified in [Pseudocode](https://en.wikipedia.org/wiki/Pseudocode), which is not a programming language.

*Hint: When in doubt, use the public test cases to check whether your implementation matches the specification!*

#### Bubble Sort
```ada
procedure Bubblesort(array):
  for unsorted_elements from length(array) down to 1 inclusive:
    for element from 0 up to unsorted_elements exclusive:
      if array[element] > array[element + 1]:
        swap(array[element], array[element + 1])
    print array
```

#### Merge Sort
```ada
procedure Mergesort(array):
  if length(array) < 2:
    return
  
  half := ceiling(length(array) / 2)       -- If odd, round up
  Mergesort(array[0 to half])              -- Recursively sort left half
  Mergesort(array[half to length(array)])  -- Recursively sort right half
  Merge(array[0 to half], array[half to length(array)])
  print array

procedure Merge(left_array, right_array):
  left_index := 0
  right_index := 0
  
  while left_index < length(left_array) and right_index < length(right_array):
    if left_array[left_index] <= right_array[right_index]
      take left_array[left_index]
      left_index += 1
    else
      take right_array[right_index]
      right_index += 1

  -- just takes the remaining elements from whichever array (only one!) has them
  take remaining(left_array, right_array)
```

#### Heap Sort
```ada
function PARENT(i) := (i - 1) / 2  -- Index of parent
function LEFT(i) := 2 * i + 1      -- Index of left child
function RIGHT(i) := 2 * i + 2     -- Index of right child 

procedure Heapsort(array):
  BuildHeap(array)
  for unsorted_elements from length(array) down to 1 inclusive:
    swap(array[0], array[unsorted_elements])
    Heapify(0, array[0 to unsorted_elements])
    print array

procedure BuildHeap(array):
  for last_not_heapified_parent from PARENT(length(array) - 1) down to 0 inclusive:
    Heapify(last_not_heapified_parent, array)

procedure Heapify(root_index, array):
  if array[root_index] >= array[LEFT(root_index)] and array[root_index] >= array[RIGHT(root_index)]:
    return  -- do nothing
  else if array[RIGHT(root_index)] >= array[LEFT(root_index)]:
    swap(array[root_index], array[RIGHT(root_index)])
    heapify(RIGHT(root_index), array)
  else:
    swap(array[root_index], array[LEFT(root_index)])
    heapify(LEFT(root_index), array)
```

You can also watch videos on the internet to see a visualization of the idea behind [bubble sort](https://studyflix.de/wirtschaftsinformatik/bubblesort-1325?topic_id=151), 
[merge sort](https://studyflix.de/wirtschaftsinformatik/mergesort-1324?topic_id=151), and [heap sort](https://studyflix.de/wirtschaftsinformatik/heapsort-1326?topic_id=151).
Keep in mind that the implementation shown there does not necessarily match our specification. In case of a discrepancy,
always follow the pseudocode descriptions given above.

> **Note:** If you have heard of a "heap" in C in terms of dynamic memory, this is *not* the same heap that we have
  here! The heap we use in heap sort is a data structure, its german name is "Halde".

## Example Outputs
In this section, we show some example runs of the program with the corresponding output.

**Command Line:** `./a2 bubble int 3 3,2,1`
```
[3, 2, 1]
--- Start sorting ---
[2, 1, 3]
[1, 2, 3]
--- Finished sorting ---
[1, 2, 3]
```

**Command Line:** `./a2 merge string 4 hello,my,dear,friend`
```
[hello, my, dear, friend]
--- Start sorting ---
[hello, my]
[dear, friend]
[dear, friend, hello, my]
--- Finished sorting ---
[dear, friend, hello, my]
```

**Command Line:** `./a2 heap string 3 C,is,amazing`
```
[C, is, amazing]
--- Start sorting ---
[amazing, C, is]
[C, amazing, is]
--- Finished sorting ---
[C, amazing, is]
```

