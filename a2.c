//---------------------------------------------------------------------------------------------------------------------
// a2.c
//
// This C program sorts arrays of integers and strings using specified sorting algorithms provided as 
// command-line arguments, including bubble, merge, and heap sorts.
// 
//
// Group: 4
//
// Author: 12231663
//---------------------------------------------------------------------------------------------------------------------
//

#include <stdio.h>

#define INPUT_BUFFER 100
#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100

//---------------------------------------------------------------------------------------------------------------------
///
/// This function calculates the length of a given string.
///
/// @param string The string whose length is to be calculated. 
///
/// @return The length of the string.
//
int getStrLength(char string[])
{
  int length = 0;
  while (*string != '\0')
  {
    length++;
    string++;
  }
  return length;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// This function converts all the lowercase characters in a string to uppercase.
///
/// @param str The string to be converted to uppercase. 
///
/// @return void
//
void toUpper(char str[])
{
  int length = getStrLength(str);

  for (int index = 0; index < length; index++) // a=97, A=65;
  {
    if (str[index] >= 'a' && str[index] <= 'z')
    {
      str[index] = str[index] - 32;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function replaces all newline characters in a string with null characters.
///
/// @param str The string in which newline characters are to be replaced with null characters.
///
/// @return void
//
void nullTerminateString(char str[])
{
  while (*str != '\0')
  {
    if (*str == '\n')
    {
      *str = '\0';
    }
    str++;
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints a message indicating the start of a sorting process.
///
/// @return void
//
void messageStartSort()
{
  printf("--- Start sorting ---\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints a message indicating the end of a sorting process.
///
/// @return void
//
void messageFinishSort()
{
  printf("--- Finished sorting ---\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function compares two strings for equality.
///
/// @param first_string The first string to be compared.
/// @param second_string The second string to be compared.
///
/// @return 1 if the strings are equal, 0 otherwise.
//
int compareTwoStrings(char first_string[], char second_string[])
{
  int str_length1 = getStrLength(first_string);
  int str_length2 = getStrLength(second_string);

  toUpper(second_string); // the input is all modified to be uppercase

  if (str_length1 != str_length2)
  {
    return 0;
  }
  for (int i = 0; i < str_length1; i++)
  {
    if (first_string[i] != second_string[i])
    {
      return 0;
    }
  }
  return 1;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks if the provided sorting algorithm is valid.
///
/// @param argv The name of the sorting algorithm to be checked. 
///
/// @return 0 if the sorting algorithm is valid, 2 otherwise.
//
int checkValidAlg(char argv[])
{
  char bubble[INPUT_BUFFER] = "BUBBLE";
  char merge[INPUT_BUFFER] = "MERGE";
  char heap[INPUT_BUFFER] = "HEAP";

  toUpper(argv);

  if (compareTwoStrings(bubble, argv) != 1 && compareTwoStrings(merge, argv) != 1 && compareTwoStrings(heap, argv) != 1)
  {
    printf("Invalid sorting algorithm!\n");
    return 2;
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function counts the number of numbers and commas in a string.
///
/// @param str The string in which numbers and commas are to be counted.
///
/// @return The number of numbers and commas in the string.
//
int countNumbersAndCommasInString(char str[])
{
  int number_of_elements = 0;
  int length = getStrLength(str);
  int is_previous_char_digit = 0;
  for (int index = 0; index < length; index++)
  {
    if (*(str + index) == ',') // the commas
    {
      number_of_elements++;
      is_previous_char_digit = 0;
    }
    else if (*(str + index) >= '0' && *(str + index) <= '9') // if the current element is a digit
    {
      if (!is_previous_char_digit) // if the previous character was not a digit
      {
        number_of_elements++;
      }
      is_previous_char_digit = 1;
    }
    else
    {
      is_previous_char_digit = 0;
    }
  }
  return number_of_elements;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks if the provided data type is valid.
///
/// @param argv The name of the data type to be checked. 
///
/// @return 0 if the data type is valid, 3 otherwise.
//
int checkDatatype(char argv[])
{
  char integer[INPUT_BUFFER] = "INT";
  char string[INPUT_BUFFER] = "STRING";

  toUpper(argv);

  if (compareTwoStrings(integer, argv) != 1 && compareTwoStrings(string, argv) != 1)
  {
    printf("Invalid data type!\n");
    return 3;
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks if a string can be interpreted as an integer.
///
/// @param str The string to be checked. 
///
/// @return 1 if the string can be interpreted as an integer, 0 otherwise.
//
int checkIfAStringIsInt(char str[])
{
  int length = getStrLength(str);

  for (int index = 0; index < length; index++)
  {
    if (!(str[index] >= '0' && str[index] <= '9'))
    {
      return 0; // not all of the elements of the string are ints
    }
  }
  return 1; // it is an integer
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function converts a string to an integer.
///
/// @param str The string to be converted to an integer. 
///
/// @return The integer representation of the string.
//
int stringToInteger(char str[])
{
  int number = 0;
  int length = getStrLength(str);

  for (int index = 0; index < length; index++)
  {
    number = number * 10 + (str[index] - '0'); // str[i] - '0', 0 has 48 ascii value and str[i] should have 48-57
  }
  return number;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function counts the number of elements in a comma-separated list.
///
/// @param str The string representing the comma-separated list.
///
/// @return The number of elements in the list.
//
int getNumberOfElements(char str[])
{
  int counter = 0;
  int length = getStrLength(str); // so zapitkite vkuluceno

  for (int index = 0; index < length; index++) // check if the list contains at least on comma
  {
    if (str[index] == ',')
    {
      counter++;
    }
  }
  if (counter == 0) // there are not commas which means there is just one element
  {
    return 1;
  }

  return (counter + 1); // number of elements will be number of , plus 1
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks if the number of elements in a list matches a given count.
///
/// @param elements_in_a_list The number of elements in the list.
/// @param count The expected number of elements in the list.
///
/// @return 0 if the numbers match, 7 if there are too many elements, and 6 if there are not enough elements.
//
int checkNumberOfElements(int elements_in_a_list, int count)
{
  if (elements_in_a_list > count)
  {
    printf("Too many elements given!\n");
    return 7;
  }
  else if (elements_in_a_list < count)
  {
    printf("Not enough elements given!\n");
    return 6;
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function extracts numbers from a comma-separated string and stores them in an array.
///
/// @param str The string from which numbers are to be extracted.
/// @param arr The array in which the extracted numbers are to be stored.
///
/// @return void
//
void extractNumbersFromString(char *str, int *arr)
{
  int length = getStrLength(str);
  int arr_index = 0;    // position in the array
  int num_index = 0;    // position it the number
  char num_buffer[100]; // buffer to store the numbers
  int is_negative = 0;

  for (int i = 0; i <= length; i++) //'\0' should be included
  {
    if (*(str + i) >= '0' && *(str + i) <= '9')
    {
      num_buffer[num_index] = *(str + i); // add the current number as a string on the numBuffer
      num_index++;                       // increment the postiton of the number, so its known how many digits does the num have
    }
    else if (*(str + i) == '-')
    {
      is_negative = 1;
    }
    else if (*(str + i) == '\0' || *(str + i) == ',')
    {
      num_buffer[num_index] = '\0';           // end the string
      int num = stringToInteger(num_buffer); // convert the string to int
      if (is_negative == 1)
      {
        num = -num;
        is_negative = 0;
      }
      arr[arr_index] = num; // add the number on the array
      arr_index++;          // increment the postion in the array
      num_index = 0;        // set it to 0 so the other number with its own digits can be proccessed
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function counts the number of commas in a string.
///
/// @param str The string in which commas are to be counted.
///
/// @return The number of commas in the string.
//
int countCommas(char str[])
{
  int counter = 0;
  while (*str != '\0')
  {
    if (*str == ',')
    {
      counter++;
    }
    str++;
  }
  return counter;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function swaps the values of two integers.
///
/// @param x Pointer to the first integer.
/// @param y Pointer to the second integer.
///
/// @return void
//
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the elements of an array from a specified start index to a specified end index.
///
/// @param arr The array whose elements are to be printed.
/// @param start The start index from which to begin printing.
/// @param end The end index at which to stop printing.
///
/// @return void
//
void printArray(int arr[], int start, int end)
{
  printf("[");
  for (int index = start; index < end; index++)
  {
    if (index != end - 1)
    {
      printf("%d, ", arr[index]);
    }
    else
    {
      printf("%d", arr[index]);
    }
  }
  printf("]\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the elements of a 2D string array.
///
/// @param arr The 2D string array whose elements are to be printed.
/// @param num_of_words The number of words (strings) in the array.
///
/// @return void
//
void printStringArray(char arr[][MAX_WORD_LENGTH], int num_of_words)
{
  for (int index = 0; index < num_of_words; index++)
  {
    printf("%s, ", arr[index]);
  }
  printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts an array of integers using the bubble sort algorithm.
///
/// @param arr The array to be sorted.
/// @param num_of_elements The number of elements in the array.
///
/// @return void
//
void bubbleSortInt(int arr[], int num_of_elements)
{
  printArray(arr,0 , num_of_elements);
  messageStartSort();

  for (int i = num_of_elements - 1; i >= 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (*(arr + j) > *(arr + j + 1))
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
    if(i!=0)//just to pass the test case, i need to print the arr once less
    {
      printArray(arr, 0,num_of_elements);
    }
  }
  messageFinishSort();
  printArray(arr, 0, num_of_elements);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function merges two subarrays of arr[].
/// First subarray is arr[l..m]
/// Second subarray is arr[m+1..r]
///
/// @param arr The array to be sorted.
/// @param l The starting index of the first subarray.
/// @param m The ending index of the first subarray and starting index - 1 of the second subarray.
/// @param r The ending index of the second subarray.
///
/// @return void
//
void merge(int arr[], int l, int m, int r)
{
  int left_size = m - l + 1;
  int right_size = r - m;

  int L[left_size];
  for (int i = 0; i < left_size; i++)
  {
    L[i] = arr[l + i];
  }
  int R[right_size];
  for (int j = 0; j < right_size; j++)
  {
    R[j] = arr[m + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < left_size && j < right_size)
  {
    if (L[i] < R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < left_size)
  {
    arr[k] = L[i];
    k++;
    i++;
  }
  while (j < right_size)
  {
    arr[k] = R[j];
    k++;
    j++;
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts an array of integers using the merge sort algorithm.
///
/// @param arr The array to be sorted.
/// @param l The starting index of the array.
/// @param r The ending index of the array.
/// @param num_of_elements The number of elements in the array.
///
/// @return void
//
void mergeSort(int arr[], int l, int r, int num_of_elements)
{
  if (l == 0 && r == num_of_elements - 1)
  {
    printArray(arr, 0, num_of_elements);
    messageStartSort();
    if (num_of_elements == 1) // If the array has only one element
    {
    printArray(arr,0, 1); // Print the array
    messageFinishSort();
    printArray(arr,0, 1); // Print the array
    }
  }

  if (l >= r)
  {
    return;
  }

  int m = l + (r - l) / 2;
  mergeSort(arr, l, m, num_of_elements);//on the left part
  mergeSort(arr, (m + 1), r, num_of_elements);//on the right part
  merge(arr, l, m, r);

  printArray(arr, l, r + 1);

  if (l == 0 && r == num_of_elements - 1)
  {
    messageFinishSort();
    printArray(arr, 0, num_of_elements);
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function calculates the maximum length of a word in a comma-separated string.
///
/// @param str The string in which to find the maximum word length.
///
/// @return The maximum word length.
//
int getMaxWordLength(char *str)
{
  int max_word_length = 0;
  int curr_word_lenth = 0;

  while (*str != '\0')
  {
    if (*str != ',')
    {
      curr_word_lenth++;
    }
    else // current char is comma
    {
      if (curr_word_lenth > max_word_length)
      {
        max_word_length = curr_word_lenth;
      }
      curr_word_lenth = 0;
    }
  }
  if (curr_word_lenth > max_word_length) // chech if the last word is the longest
  {
    max_word_length = curr_word_lenth;
  }
  return max_word_length;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function copies a string from source to destination.
///
/// @param source The string to be copied.
/// @param destination The destination where the string will be copied.
/// @param length The maximum number of characters to be copied.
///
/// @return void
//
void myStrCopy(char *source, char *destination, int length)
{
  int index;
  for (index = 0; index < length && source[index] != '\0'; index++)
  {
    *(destination + index) = *(source + index);
  }
  destination[index] = '\0';
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function extracts strings from a comma-separated input string and stores them in an array.
///
/// @param str The comma-separated input string.
/// @param words The array where the extracted strings will be stored.
///
/// @return void
//
void extractStringsFromInputString(char str[], char words[][MAX_WORD_LENGTH])
{
  char word[MAX_WORD_LENGTH];
  int char_index = 0;
  int arr_index = 0;

  while (*str != '\0')
  {
    if (*str != ',')
    {
      word[char_index] = *str;
      char_index++;
      str++;
    }
    else
    {
      word[char_index] = '\0';
      myStrCopy(word, words[arr_index], char_index + 1);
      arr_index++;
      char_index = 0;
      str++;
    }
  }
  if (char_index > 0) // for the last word
  {
    word[char_index] = '\0';
    myStrCopy(word, words[arr_index], char_index + 1);
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints an array of strings.
///
/// @param count The number of strings in the array.
/// @param words The array of strings to be printed.
///
/// @return void
//
void printWords(int count, char words[count][MAX_WORD_LENGTH])
{
  printf("[");
  for (int index = 0; index < count; index++)
  {
    if (index != count - 1)
    {
      printf("%s, ", words[index]);
    }
    else
    {
      printf("%s", words[index]);
    }
  }
  printf("]\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function swaps the contents of two strings.
///
/// @param str1 The first string.
/// @param str2 The second string.
///
/// @return void
//
void swapStrings(char str1[], char str2[])
{
  char temp[MAX_WORD_LENGTH];

  myStrCopy(str1, temp, getStrLength(str1) + 1);
  myStrCopy(str2, str1, getStrLength(str2) + 1);
  myStrCopy(temp, str2, getStrLength(temp) + 1);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function compares two strings lexicographically.
///
/// @param str1 The first string.
/// @param str2 The second string.
///
/// @return An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than,
///         to match, or be greater than str2.
//
int myStrCompare(char str1[], char str2[])
{
  int index = 0;
  while (str1[index] != '\0' && str2[index] != '\0')
  {
    if (str1[index] != str2[index])
    {
      return (str1[index] - str2[index]); // postive that means the "bigger" words comes first as it shouldnot
    }
    index++;
  }
  return (str1[index] - str2[index]); // we return 0
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints a range of words from an array of strings.
///
/// @param l The starting index of the range.
/// @param r The ending index of the range.
/// @param words The array of words.
///
/// @return void
//
void printWordsInRange(int l, int r, char words[][MAX_WORD_LENGTH]) 
{
  printf("[");
  for (int index = l; index <= r; index++) 
  {
    printf("%s", words[index]);
    if (index < r) 
    {
      printf(", ");
    }
    }
  printf("]\n");
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts an array of strings lexicographically using the bubble sort algorithm.
///
/// @param num_of_words The number of words in the array.
/// @param words The array of words to be sorted.
///
/// @return void
//
void bubbleSortString(int num_of_words, char words[][MAX_WORD_LENGTH])
{
  messageStartSort();

  if(num_of_words == 1) // If the array has only one element
  {
    printWords(num_of_words, words); // Print the array
  }

  for (int i = 0; i < num_of_words - 1; i++) // runs for each word exept the last one
  {
    for (int j = 0; j < num_of_words - i - 1; j++) //
    {
      if (myStrCompare(words[j], words[j + 1]) > 0) // is the char in the first word is "bigger"
      {
        swapStrings(words[j], words[j + 1]);
      }
    }
    printWords(num_of_words, words);
  }
  messageFinishSort();
  printWords(num_of_words, words);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function merges two subarrays of strings into one sorted array.
///
/// @param words The array of words to be sorted.
/// @param l The starting index of the first subarray.
/// @param m The ending index of the first subarray and starting index - 1 of the second subarray.
/// @param r The ending index of the second subarray.
///
/// @return void
//
void mergeString(char words[][MAX_WORD_LENGTH], int l, int m, int r)
{
  char L[MAX_NUM_WORDS][MAX_WORD_LENGTH];
  char R[MAX_NUM_WORDS][MAX_WORD_LENGTH];

  int left_size = m - l + 1;
  int right_size = r - m;

  int i = 0;
  int j = 0;
  int k = l;

  for(int i = 0; i < left_size; i++)
  {
    myStrCopy(words[l + i], L[i], MAX_WORD_LENGTH);
  }

  for(int j = 0; j < right_size; j++)
  {
    myStrCopy(words[m + 1 + j], R[j], MAX_WORD_LENGTH);
  }

  while(i < left_size && j < right_size)
  {
    if(myStrCompare(L[i], R[j]) > 0)//word on the left has bigger accii value
    {
      myStrCopy(R[j],words[k], MAX_WORD_LENGTH);
      j++;
    }
    else //word on the right has bigger asci value
    {
      myStrCopy(L[i],words[k], MAX_WORD_LENGTH);
      i++;
    }
    k++;
  }

  while(i < left_size)
  {
    myStrCopy(L[i],words[k], MAX_WORD_LENGTH);
    i++;
    k++; 
  }

  while(j < right_size)
  {
    myStrCopy(R[j],words[k], MAX_WORD_LENGTH);
    j++;
    k++; 
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts an array of strings lexicographically using the merge sort algorithm.
///
/// @param num_of_words The number of words in the array.
/// @param l The starting index of the array to be sorted.
/// @param r The ending index of the array to be sorted.
/// @param words The array of words to be sorted.
///
/// @return void
//
void mergeSortString(int num_of_words, int l, int r, char words[][MAX_WORD_LENGTH])
{
  if (l == 0 && r == num_of_words - 1)
  {
    printWords(num_of_words, words);
    messageStartSort();
    if (num_of_words == 1) // If the array has only one element
    {
      printWords(num_of_words, words); // Print the array
      messageFinishSort();
      printWords(num_of_words, words); // Print the array

    }
  }

  if(l >= r)
  {
    return;
  }

  int m = l + (r - l)/2;
  mergeSortString(num_of_words, l, m, words);
  mergeSortString(num_of_words, (m+1), r, words);
  mergeString(words, l, m, r);

  printWordsInRange(l,r, words);

  if (l == 0 && r == num_of_words - 1)
  {
    messageFinishSort();
    printWords(num_of_words, words);
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function handles the bubble sort operation for an array of integers.
///
/// @param argv[] The string containing the comma-separated integers.
/// 
///
/// @return void
//
void handleBubbleInt(char argv[])
{
    int number_of_elements_with_commas = countNumbersAndCommasInString(argv);
    int arr[number_of_elements_with_commas]; // array to hoold the numbers

    extractNumbersFromString(argv, arr);
    // Perform bubble sort on integers
    int number_of_elements_without_commas = getNumberOfElements(argv);
    bubbleSortInt(arr, number_of_elements_without_commas);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function handles the bubble sort operation for an array of strings.
///
/// @param argv[] The string containing the comma-separated words.
/// @param count The number of words in the string.
///
/// @return void
//
void handleBubbleString(char argv[], int count)
{
    char words[count][MAX_WORD_LENGTH]; // 2d array to store the words separatly
    // counts = num of individial strings
    extractStringsFromInputString(argv, words);
    printWords(count, words);
    bubbleSortString(count, words);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function handles the merge sort operation for an array of integers.
///
/// @param argv[] The string containing the comma-separated numbers.
/// @param count The number of numbers in the string.
///
/// @return void
//
void handleMergeInt(char argv[])
{
    int number_of_elements_with_commas = countNumbersAndCommasInString(argv);
    int arr[number_of_elements_with_commas]; // array to hoold the numbers

    extractNumbersFromString(argv, arr);
    // Perform bubble sort on integers
    int number_of_elements_without_commas = getNumberOfElements(argv);
    // numberOfElementsWithoutCommas=length of the array
    mergeSort(arr, 0, (number_of_elements_without_commas - 1), number_of_elements_without_commas);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function handles the merge sort operation for an array of strings.
///
/// @param argv[] The string containing the comma-separated words.
/// @param count The number of words in the string.
///
/// @return void
//
void handleMergeString(char argv[], int count)
{
    char words[count][MAX_WORD_LENGTH];
    extractStringsFromInputString(argv, words);
    mergeSortString(count ,0 , count-1 , words);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function maintains the max heap property for an array of integers.
///
/// @param arr[] The array of integers to be sorted.
/// @param index The index of the element to be heapified.
/// @param heap_size The size of the heap.
///
/// @return void
//
void maxHeapify(int arr[], int index, int heap_size)
{
  int left_child = 2*index+1;
  int right_child= 2*index+2;
  int largest;

  if(left_child < heap_size && arr[left_child] > arr[index])
  {
    largest = left_child;
  }
  else
  {
    largest = index;
  }

  if(right_child < heap_size && arr[right_child] > arr[largest])
  {
    largest = right_child;
  }
  if(largest != index)
  {
    int temp = arr[index];
    arr[index]= arr[largest];
    arr[largest] = temp;
    maxHeapify(arr, largest, heap_size);
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function builds a max heap from a given array.
///
/// @param arr[] The array from which to build the heap.
/// @param num_of_elements The number of elements in the array.
///
/// @return void
//
void buildMaxHeap(int arr[], int num_of_elements)
{
  int heap_size = num_of_elements;
  for(int index = (num_of_elements/2) - 1; index >= 0; index--)
  {
    maxHeapify(arr, index, heap_size);
  }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts an array of integers using the heap sort algorithm.
///
/// @param arr[] The array to be sorted.
/// @param count The number of elements in the array.
///
/// @return void
//
void heapSort(int arr[],int count)
{
  printArray(arr,0,count);
  messageStartSort();
  buildMaxHeap(arr, count);
  for(int index = count - 1; index > 0; index--)
  {
    int temp = arr[0];
    arr[0] = arr[index];
    arr[index] = temp;
    maxHeapify(arr, 0, index);
    printArray(arr, 0, count);
  }
  messageFinishSort();
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function handles the heap sort operation for an array of integers.
///
/// @param argv[] The string containing the comma-separated numbers.
/// @param count The number of numbers in the string.
///
/// @return void
//
void handleHeapInt(char argv[], int count)
{
  int arr[100];
  extractNumbersFromString(argv, arr);
  heapSort(arr,count);
  printArray(arr, 0, count);
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks the validity of command-line arguments.
///
/// @param argc The number of command-line arguments.
/// @param argv[] The array containing the command-line arguments.
///
/// @return int Returns 0 if all arguments are valid, otherwise returns an error code.
//
int checkArguments(int argc, char *argv[])
{
  int exit_code;

  if (argc != 5)
  {
    printf("Usage: ./a2 <algorithm> <type> <count> <data>\n");
    return 1;
  }

  exit_code = checkValidAlg(argv[1]);
  if (exit_code != 0)
  {
    return exit_code;
  }

  exit_code = checkDatatype(argv[2]);
  if (exit_code != 0)
  {
    return exit_code;
  }
  int flag = checkIfAStringIsInt(argv[3]);
  if (flag == 0) // it is not an int
  {
    printf("Element count is not an integer!\n");
    return 4;
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This is the main function of the program. It checks the validity of the command line arguments, 
/// converts the third argument to an integer, checks if it is less than 1, and checks the number of elements in the list.
/// Depending on the command line arguments, it calls the appropriate function to handle the sorting operation.
///
/// @param argc The number of command line arguments.
/// @param argv[] The array containing the command line arguments.
///
/// @return int Returns 0 if the program runs successfully, and a non-zero exit code otherwise.
//
int main(int argc, char *argv[])
{
  int exit_code = checkArguments(argc, argv);
  if(exit_code != 0)
  {
    return exit_code;
  }

  int count = stringToInteger(argv[3]);
  if (count < 1)
  {
    printf("Invalid count!\n");
    return 5;
  }

  int elementsInAList = getNumberOfElements(argv[4]);
  exit_code = checkNumberOfElements(elementsInAList, count);

  if (exit_code != 0)
  {
    return exit_code;
  }

  if (compareTwoStrings(argv[1], "BUBBLE") == 1 && compareTwoStrings(argv[2], "INT") == 1)
  {
    handleBubbleInt(argv[4]);
  }

  if (compareTwoStrings(argv[1], "BUBBLE") == 1 && compareTwoStrings(argv[2], "STRING") == 1)
  {
    handleBubbleString(argv[4], count);
  }

  if (compareTwoStrings(argv[1], "MERGE") == 1 && compareTwoStrings(argv[2], "INT") == 1)
  {
    handleMergeInt(argv[4]);
  }

  if(compareTwoStrings(argv[1], "MERGE") == 1 && compareTwoStrings(argv[2], "STRING")==1)
  {
    handleMergeString(argv[4],  count);
  }

  if(compareTwoStrings(argv[1], "HEAP") == 1 && compareTwoStrings(argv[2], "INT")==1)
  {
    handleHeapInt(argv[4],  count);
  }
  return 0;
}
