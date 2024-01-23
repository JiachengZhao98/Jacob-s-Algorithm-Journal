         /*
                           _ooOoo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          O\  =  /O
                       ____/`---'\____
                     .'  \\|     |//  `.
                    /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                 Buddha bless         NO BUG
        */

# Some of my answers and thoughts when solving LeetCode and other interview problems.

- Suggestions of improvement are strongly welcomed.

- Including some problems from Amazon Online Assessment and Virtual Onsite Interview

---

# Programming language tips from learning how to solve leetcode problems

## Content

+ [CPP](#CPP)
+ [Java](#Java)
+ [Python](#Python)


---

### CPP <a name="CPP"></a>

+ [vector](#vector)
+ [deque](#deque)
+ [priority_queue](#priority_queue)
+ [string](#string)
+ [hash_table](#hashtable)

#### ```vector```<a name="vector"></a>:
+ The usage of a 2-D ```vector``` ➡️ [click here](https://www.digitalocean.com/community/tutorials/2d-vectors-in-c-plus-plus)

+ About built-in sorting function for ```vector```:```vector.sort()```:
	- The C++ standard specifies that the worst-case runtime of std::sort() is in O(n log n)
	-  the usage for the third argument:
		- ``` bool myfunction (int i,int j) { return (i<j); } //acending ```
		- ```bool myfunction2 (int i,int j) { return (i>j); }  //desending ```
		- ```static bool cmp(int a, int b) {return abs(a) > abs(b); // desending based on absolute values} ```


+ pay more attention to the value of **i** when using the *for* loop, 'cause when one loop is down **i** will ++


+ how to get the number of rows and columns from a 2-D ```vector```:
	+ ```int size_row = vec.size();  //acquire the number of row ```
	+ ``` int size_col = vec[0].size();  //acquire the number of column```

+ how to round the output into two digits ( just remembering the code below is enough...):

```
#include<iomanip>  //header file
cout<<setiosflags(ios::fixed)<<setprecision(2);
```

+ ``` vector::resize(int n, int val)```
The function alters the container’s content in actual by inserting or deleting the elements from it. It happens so,
If the given value of n is less than the size at present then extra elements(at the END of the ```vector```) are demolished.
If n is more than current size of container then upcoming elements are appended at the end of the vector.

+ ```vector``` Initialization:

```
vector<int> ilist1; // first
vector<int> ilist2(ilist1);  // second
vector<int> ilist3  = ilist1; // third
// ilist1, ilist2 and ilist3 are all the SAME !!!

vector<int> ilist = {1,2,3.0,4,5,6,7};
vector<int> ilist {1,2,3.0,4,5,6,7};
// If met some values that are not int, this func will automatically change the value type.

 vector<int> ilist3(ilist.begin()+2,ilist.end()-1); //e.g. ilist3 = {3, 4, 5, 6}
// the vector only copies to the front value of the second value input

 vector<int> ilist4(7); // this vector will contain 7 values, which are not initialized.

 vector<int> ilist5(7,3); // there are seven integers in this vector, which values are all 3.

 vector<vector<vector<int>>> dp = vector(k, vector(m, vector(n, -1)));
 // initialize a 2-D vector with m rows, n columns and the default value of -1
```

+ How to delete elements within a ```vector```:

```
vector::erase()
iterator erase ( iterator position ); //delete the value in the certain position

iterator erase ( iterator first, iterator last ); // delete a certain sequence of elements within a vector

vector::pop_back()
   void pop_back ( ); // delete the last element in a vector. NO return values
```

+ How to copy a ```vector``` to another ```vector```: ```a = b;```, Where ```a``` and ```b``` are ```vector```.

+ We can NOT use ```new``` to create a ```vector```.

+ The difference between ```vector<vector<int>> vec``` and ```vector<int> F[N]```:
In the first case we are creating a dynamic array of dynamic arrays (vector of vectors). The size of each vector could be changed at the run-time and all objects will be allocated on the heap.
In the second case we are creating a fixed-size array of vectors. You have to define N at compile-time, and all vectors will be placed on the stack, however, each vector will allocate elements on the heap.


#### ```deque```<a name="deque"></a>:

➡️ [check here](https://www.geeksforgeeks.org/deque-cpp-stl/)

#### ```priority_queue```<a name="priority_queue"></a>:
➡️ [check here](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)

+ two examples:

```
priority_queue<int> pq; // High to low

priority_queue<int, vector<int>, greater<int>> pq; // Low to High
```

#### ```string```<a name="string"></a>:

+ ```string``` DOES have a ```push_back``` function

+ We can convert ```string``` to ```int``` in multiple ways. The easiest way to do this is by using the ```std::stoi()``` function introduced in C++11; The differences between ```atoi()``` and ```stoi()```: ➡️ [check here](https://stackoverflow.com/questions/20583945/what-is-the-difference-between-stdatoi-and-stdstoi)

+ convert ```string``` to ```char```:

```
string str="adcd";
char *p=(char*)str.c_str();
```

+ convert ```string``` to ```int```:

```
 std::string str = "123";
    int num;
	// using stoi() to store the value of str1 to x
    num = stoi(str);
```

+ ```stringstream```: ➡️ [check here](https://www.geeksforgeeks.org/stringstream-c-applications/). We should use ```stringstream``` to eliminate the space between words in a sentence, which is a ```string```.

#### ```Hash Table```<a name="hashtable"></a>:

###### ```set```:
+ ```set``` does NOT allow duplicate elements and elements in ```set``` are ordered (ascending).

+ ```unordered_set```does NOT allow duplicate elements and elements in ```set``` are NOT ordered.

+ methods in ```set```:
	+ ```begin()```	Returns an iterator to the first element in the set.

	+ ```end()``` 	Returns an iterator to the theoretical element that follows the last element in the set.

	+ ```rbegin()``` 	Returns a reverse iterator pointing to the last element in the container.

	+ ```rend()```	Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
	+ ```crbegin()```	Returns a constant iterator pointing to the last element in the container.
	+ ```crend()```	Returns a constant iterator pointing to the position just before the first element in the container.
	+ ```cbegin()```	Returns a constant iterator pointing to the first element in the container.
	+ ```cend()```	Returns a constant iterator pointing to the position past the last element in the container.
	+ ```size()```	Returns the number of elements in the set.
max_size()	Returns the maximum number of elements that the set can hold.
	+ ```empty()```	Returns whether the set is empty.
	+ ```insert(const g)``` 	Adds a new element ‘g’ to the set.
	+ ```iterator insert (iterator position, const g)``` Adds a new element ‘g’ at the position pointed by the iterator.
	+ ```erase(iterator position)``` 	Removes the element at the position pointed by the iterator.
	+ ```erase(const g)```	Removes the value ‘g’ from the set.
	+ ```clear()``` 	Removes all the elements from the set.
	+ ```key_comp() / value_comp()``` 	Returns the object that determines how the elements in the set are ordered (‘<‘ by default).
	+ ```find(const g)```	Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
	+ ```count(const g)```	Returns 1 or 0 based on whether the element ‘g’ is present in the set or not.
	+ ```lower_bound(const g)```	Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
	+ ```upper_bound(const g)```	Returns an iterator to the first element that will go after the element ‘g’ in the set.

###### ```map```:

+ The ```key``` of ```map``` are sorted ascending by default.

+ When we use ```map.find(KEY)``` function, we can only search for the ```key``` part. We can NOT search the ```value``` part.
+ Two ways to make iterator point to the second element of map:
	1. ```it = ++map.begin();```
	2. ```it = next(map.begin());```

+ The code you provided uses a range-based for loop, which iterates directly over the elements of the container (in this case, the `std::map`). The variable `it` in this context is not an iterator; rather, it's a reference to the actual element of the map. Since each element of a `std::map` is a `std::pair`, you can use `it.first` and `it.second` to access the key and value, respectively.

Here's a breakdown:

1. Using iterators (traditional way):

```cpp
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    // 'it' is an iterator, so we use '->' to access members of the pair
    auto key = it->first;
    auto value = it->second;
}
```

2. Using range-based for loop:

```cpp
for (auto& it : myMap) {
    // 'it' is a reference to the element (pair), so we use '.' to access members
    auto key = it.first;
    auto value = it.second;
}
```

In the range-based for loop, `it` directly refers to the key-value pair, so we use the dot operator `.` to access its members. In the traditional loop with iterators, `it` is an iterator pointing to the key-value pair, so we use the arrow operator `->` to access its members.


##### compile instructions:
```$ g++ -std=c++11 your_file.cpp -o your_program```

##### show current path in terminal:
```pwd```(means: **p**rint **w**orking **d**irectory)

zip a file: ```zip -r archive_name.zip folder_to_compress```

In C++, the `.substr()` function is a member of the `std::string` class and is used to create a substring from a string object. The function has the following signature:

```cpp
string substr (size_t pos = 0, size_t len = npos) const;
```

- `pos` is the starting position of the substring within the string.
- `len` is the number of characters to include in the substring.

If `len` is not provided, or if it is `std::string::npos` (the default), the function returns a substring that starts at `pos` and extends to the end of the string.

Here's how you can use `substr`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Hello World";

    // Get substring starting from position 6 of length 5
    std::string part = str.substr(6, 5);

    std::cout << part << std::endl;  // Outputs "World"

    // Get substring from position 2 to the end of the string
    std::string rest = str.substr(2);

    std::cout << rest << std::endl;  // Outputs "llo World"

    return 0;
}
```

In this example, `part` contains the substring "World" which starts at index 6 (0-based index) and spans 5 characters. `rest` contains the substring "llo World" which starts at index 2 and goes to the end of the string. If the starting position is beyond the end of the string, or if the starting position is valid but the specified length extends beyond the end of the string, `std::string::substr` will throw an `std::out_of_range` exception.

The difference between these two function definitions in C++ lies in how the `index` parameter is passed and used:

1. **`string dec(string& s, int& index)`**:
    - In this function, `index` is passed by **reference**, indicated by the `&` symbol.
    - Any changes made to `index` inside the function will affect the variable in the calling function, as both the function parameter and the original variable refer to the same memory location.
    - This approach is often used when you want the function to modify the original variable, or when you want to avoid copying for performance reasons (though for simple data types like `int`, this is usually not a concern).

2. **`string dec(string& s, int index)`**:
    - Here, `index` is passed by **value**. This means a copy of `index` is created and used inside the function.
    - Changes made to `index` within the function do not affect the original variable. The function works with its own independent copy.
    - This is the standard way to pass variables when you don't need the function to modify the original variable, or when you want to ensure that the function has its own isolated copy.

In summary, the key difference is in how modifications to the `index` parameter inside the function affect the original variable: they will alter the original in the first case (passed by reference), but not in the second case (passed by value).x

In C++, a constructor is a special member function of a class that is automatically called when an object of that class is created. **Constructors have the same name as the class and are used to initialize the object's member variables, allocate resources, and perform any setup operations that the object might need before it is used.**

In C++, you can't execute such statements directly in the class scope. You need to initialize these members inside a constructor or use an initialization list.

Key characteristics of constructors include:

1. **Same Name as Class:** Constructors have the same name as the class and do not have a return type, not even `void`.

2. **Automatic Invocation:** They are called automatically when an object is created, either through direct instantiation or through copy construction.

3. **Overloading:** Constructors can be overloaded, meaning a class can have multiple constructors with different parameters. This allows for different ways of initializing objects of the class.

4. **Default Constructor:** If no constructors are defined by the programmer, the compiler provides a default constructor. However, as soon as a custom constructor is defined, the default constructor is no longer provided unless explicitly defined.

5. **Copy Constructor:** A special type of constructor, called a copy constructor, is used to create a new object as a copy of an existing object.

6. **Initialization Lists:** Constructors can use initialization lists to initialize member variables before the body of the constructor is executed.

Here's an example illustrating a basic constructor:

```cpp
class Rectangle {
    private:
        int width, height;

    public:
        // Constructor
        Rectangle(int w, int h) : width(w), height(h) {
            // Initialization list is used to set width and height
        }

        int area() {
            return width * height;
        }
};

int main() {
    Rectangle rect(10, 20);  // Creates a Rectangle object with width 10 and height 20
    std::cout << "Area: " << rect.area() << std::endl;  // Outputs the area of the rectangle
    return 0;
}
```

In this example, `Rectangle(int w, int h)` is the constructor for the `Rectangle` class. It initializes the `width` and `height` of the rectangle using an initialization list. When you create a `Rectangle` object with `Rectangle rect(10, 20);`, this constructor is called to initialize the `rect` object.

In C++, there are several functions similar to `max_element()` that are useful for working with vectors and other containers. These functions are part of the `<algorithm>` header and operate on ranges specified by iterators. Here are some key functions:

1. **`min_element()`**:
   - Finds the smallest element in a range.
   - Usage is similar to `max_element()`.
   - Can also take a custom comparison function.

2. **`find()`**:
   - Finds the first occurrence of a value in a range.
   - Returns an iterator to the found element, or the end iterator if the element is not found.

3. **`find_if()` and `find_if_not()`**:
   - Find the first element satisfying a predicate (`find_if`) or not satisfying it (`find_if_not`).
   - Takes a unary predicate as an additional argument.

4. **`count()` and `count_if()`**:
   - `count()` returns the number of elements equal to a given value.
   - `count_if()` counts elements satisfying a predicate.

5. **`accumulate()`** (from `<numeric>` header):
   - Computes the sum of a range of elements.
   - Can also take a custom binary operation.

6. **`transform()`**:
   - Applies a function to a range of elements and stores the result in another range.

7. **`sort()`**:
   - Sorts elements in a range.
   - Can also take a custom comparison function for sorting based on specific criteria.

8. **`partial_sort()`**:
   - Sorts the first N elements of a range, leaving the rest in an unspecified order.

9. **`nth_element()`**:
   - Partially sorts a range such that the element at the N-th position is the element that would be in that position in a fully sorted array.

10. **`unique()`**:
    - Removes consecutive duplicate elements in a range.

11. **`copy()` and `copy_if()`**:
    - Copies elements from one range to another.
    - `copy_if()` copies elements satisfying a specific condition.

12. **`reverse()`**:
    - Reverses the order of elements in a range.

13. **`rotate()`**:
    - Rotates the elements in a range.

14. **`fill()` and `fill_n()`**:
    - Assigns a given value to elements in a range.

These functions provide a wide range of operations that can be performed on vectors and other container types in C++. Each of these functions offers unique capabilities and can be incredibly powerful when combined in different ways to manipulate data stored in containers.

In C++ and many other programming languages, both `i++` and `++i` are used to increment the value of `i` by 1. However, there is a subtle difference in how they operate, especially when used in expressions.

1. **Post-Increment (`i++`)**:
   - This is known as the post-increment operator.
   - It increments `i` after its current value has been used.
   - In an expression, `i++` returns the value of `i` before it is incremented.
   - Example: If `i = 5`, then `int j = i++;` will set `j` to 5, and then `i` becomes 6.

2. **Pre-Increment (`++i`)**:
   - This is known as the pre-increment operator.
   - It increments `i` before its current value is used.
   - In an expression, `++i` returns the value of `i` after it is incremented.
   - Example: If `i = 5`, then `int j = ++i;` will first increment `i` to 6, and then `j` is set to 6.

### Performance Considerations:

- **In Primitive Types**: For primitive data types (like `int`, `float`), there's generally no performance difference between `i++` and `++i`.
- **In Objects and Iterators**: For objects (like iterators in STL containers), `++i` is often more efficient than `i++` because `i++` might create a temporary object to hold the original value of `i` before incrementing.

### When to Use:

- **Use `i++`**: When you need the original value of `i` before incrementing, in the same expression.
- **Use `++i`**: When you do not need the original value, or in loops where the value of the increment expression is not used (like in `for` loops).

In simple loops, either can be used, but `++i` is often recommended in C++ due to its potential efficiency with non-primitive types. However, in practice, modern compilers are often smart enough to optimize both cases, so the difference is negligible.

### ```This``` in cpp:

In the previous code, `this` is a keyword in C++ that refers to the current object instance within a class member function. It's a pointer to the object on which the member function is being called. When you use `this` inside a class method, you are referring to the object that the method is acting upon.

Let's look at the usage of `this` in the context of the provided `HitCounter` class code:

### Example Usage in `HitCounter` class:

1. **In the `hit` method**:

   ```cpp
   void hit(int timestamp) {
       this->hits.push(timestamp);
   }
   ```

   - `this->hits` refers to the `hits` member of the current instance of the `HitCounter` class.
   - `this->hits.push(timestamp)` means "call the `push` method on the `hits` queue of this particular instance of `HitCounter`, and pass `timestamp` as an argument."

2. **In the `getHits` method**:

   ```cpp
   int getHits(int timestamp) {
       while (!this->hits.empty()) {
           // ...
       }
       return this->hits.size();
   }
   ```

   - Similarly, `this->hits.empty()` and `this->hits.size()` refer to calling the `empty()` and `size()` methods, respectively, on the `hits` queue of the current `HitCounter` object.

### Purpose of Using `this`:

- **Clarification**: It makes it clear that you are referring to a member variable or method of the current object.
- **Avoiding Name Conflicts**: In cases where a local variable or parameter has the same name as a member variable, using `this` can help differentiate between them.
- **Consistency**: Some developers use `this` consistently for accessing member variables and methods for code clarity and consistency.

In the context of your example, `this` is used to access the `hits` queue that belongs to the instance of `HitCounter` that the method is being called on.

####```std::next_permutation()``` in cpp

The `std::next_permutation` function in C++ is a part of the `<algorithm>` standard library. It is used to rearrange the elements in a range into the next lexicographically greater permutation. In simpler terms, it takes a sequence (like an array or vector) and transforms it into the next permutation that is greater than the current arrangement, based on the order of the elements.

Here's how it works:

1. **Input**: The function takes two iterators as arguments, typically the beginning and end of a container (like a vector or array). These iterators define the range of elements to permute.

2. **Operation**: It rearranges the elements in this range into the next permutation that is greater in the lexicographical order. The function considers all elements in the range, and if possible, it creates a new permutation where the sequence of these elements is the next highest arrangement.

3. **Return Value**: The function returns `true` if it successfully finds and applies the next permutation. If the elements are in their last possible permutation (highest lexicographical order), the function rearranges them into the first (lowest) permutation and returns `false`.

4. **Usage**: This function is often used in loops to generate all possible permutations of a sequence, as it will sequentially produce all permutations in lexicographical order until all permutations have been exhausted.

Here's a simple example in C++:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3};

    do {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));

    return 0;
}
```

In this example, `std::next_permutation` is used to generate and print all permutations of the vector `{1, 2, 3}`.

---

#### use ```sort()``` to sort a container in descending order:

take vector as an example:

```sort(vector.rbegin(), vector.rend())```

### Java <a name="Java"></a>

---

### Python <a name="Python"></a>

+ [string](#string)
+ [List](#List)

##### ```string``` <a name="string"></a>:
+ use ```rstrip()``` to ensure that there is NO space at the end of a ```string```

##### ```List``` <a name="List"></a>:

+ use ```List_name[-1]``` to access the last element within a ```List```

+ Python lambda function:➡️ [check here](https://www.w3schools.com/python/python_lambda.asp)

+ Python ```List_name.sort()``` Method: ➡️ [check here](https://www.w3schools.com/python/ref_list_sort.asp)

+ Python ```List``` methods: ➡️ [check here](https://www.w3schools.com/python/python_ref_list.asp) , pay attention to the difference between the ```.append()``` and ```.extend()```.


In Python, a ```set``` is a collection of **unique** items. Here's how you can define and use sets:

1. **Defining a Set Using Curly Braces**:

   ```python
   fruits = {"apple", "banana", "cherry"}

   print(fruits)  # Outputs: {'apple', 'cherry', 'banana'}
   ```

2. **Defining a Set Using the `set()` Constructor**:

   ```python
   fruits = set(["apple", "banana", "cherry"])

   print(fruits)  # Outputs: {'apple', 'cherry', 'banana'}
   ```

   Note: Using the `set()` constructor is especially useful when converting other data types (like lists or tuples) to sets.

3. **Adding an Element to a Set**:

   ```python
   fruits.add("orange")
   print(fruits)  # Outputs: {'apple', 'cherry', 'banana', 'orange'}
   ```

4. **Removing an Element from a Set**:

   ```python
   fruits.remove("apple")  # Raises an error if "apple" is not found
   fruits.discard("apple")  # Does not raise an error if "apple" is not found
   ```

5. **Checking if an Element is in a Set**:

   ```python
   if "banana" in fruits:
       print("Banana is in the set")
   ```

6. **Union of Two Sets**:

   ```python
   fruits1 = {"apple", "banana", "cherry"}
   fruits2 = {"grape", "orange", "apple"}  # Note: "apple" is common
   union_set = fruits1 | fruits2
   print(union_set)  # Outputs: {'grape', 'apple', 'cherry', 'orange', 'banana'}
   ```

7. **Intersection of Two Sets**:

   ```python
   common_fruits = fruits1 & fruits2
   print(common_fruits)  # Outputs: {'apple'}
   ```

Remember, sets are unordered, so the items might not appear in the order you expect when you print or iterate over a set. Also, sets are mutable, but the elements themselves need to be of a type that is hashable (which means you can't have lists or dictionaries as set elements).


### filter() and join()

#### filter() Function
The `filter()` function allows you to process an iterable (like a list, tuple, etc.) and extract elements based on a specified condition.

- **Syntax**: `filter(function, iterable)`
- **Parameters**:
  - `function`: A function that tests each element in the iterable to return `True` or `False`. If `None`, it simply checks for the truthiness of each element.
  - `iterable`: The iterable (like list, tuple, etc.) whose elements are tested by the function.
- **Return Value**: Returns an iterator that includes only those elements for which the `function` returns `True`.

Example:

```python
numbers = [1, 2, 3, 4, 5, 6]
even_numbers = filter(lambda x: x % 2 == 0, numbers)
print(list(even_numbers))  # Output: [2, 4, 6]
```

In this example, `filter()` is used with a lambda function to extract even numbers from the list.

#### join() Method
The `join()` method is a string method used to join elements of an iterable into a single string, with a specified separator.

- **Syntax**: `separator.join(iterable)`
- **Parameters**:
  - `iterable`: An iterable (like list, tuple, etc.) whose elements are strings.
  - `separator`: The string that separates the elements in the resulting string.
- **Return Value**: Returns a string, which is the concatenation of the strings in the iterable, separated by the specified `separator`.

Example:

```python

words = ['Hello', 'World']

sentence = ' '.join(words)

print(sentence)  # Output: "Hello World"
```

In this example, `join()` is used to concatenate the elements of the list `words` into a single string, with a space as the separator.

### Using filter() and join() Together
Often, `filter()` and `join()` are used in combination to filter out unwanted elements and then join the remaining elements into a single string.

For example:

```python
words = ['Python', '', 'is', None, 'awesome']

filtered_words = filter(None, words)

sentence = ' '.join(filtered_words)

print(sentence)  # Output: "Python is awesome"
```

In this case, `filter(None, words)` removes any empty strings or `None` elements from the list `words`. The `join()` method then concatenates the remaining elements into a single string, separated by spaces.

This combination is particularly useful for cleaning up data and preparing strings for display or further processing.

### @cache
In Python, `@cache` is a decorator provided by the `functools` module, introduced in Python 3.9. It's a shorthand for `@functools.cache`, and it's used to add memoization to a function. Memoization is an optimization technique that stores the results of expensive function calls and returns the cached result when the same inputs occur again.

When you apply the `@cache` decorator to a function, Python remembers the function's return values for each set of parameters it has seen. The next time you call the function with the same parameters, Python retrieves the result from the cache instead of recomputing it.

Here's a basic example of how `@cache` is used:

```python

from functools import cache

@cache
def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(10))  # This will compute the value.
print(fibonacci(10))  # This will retrieve the value from the cache.

```

In this example, the `fibonacci` function calculates the nth Fibonacci number. Without caching, this function would be inefficient for large `n` because it recalculates the same values repeatedly. With `@cache`, once a Fibonacci number is calculated, it's stored in the cache, so subsequent calls with the same argument return instantly.

#### Key Points:

- `@cache` stores the results of function calls in a cache to avoid redundant calculations.
- It's useful for functions with expensive computations that are called repeatedly with the same arguments.
- The cache persists until the program exits, which can be a consideration for memory usage if the function is called with many different arguments.
- `@cache` is a feature available in Python 3.9 and later. For earlier versions, you can use `@functools.lru_cache(maxsize=None)` which offers similar functionality with a few additional features.


The `datetime` module in Python is part of the standard library, providing classes for manipulating dates and times. It is one of the most powerful modules for working with time-related data, offering a wide range of functionalities. Understanding this module and its `datetime` object is essential for many programming tasks involving date and time manipulation.

### Overview of the `datetime` Module

1. **Purpose**: The `datetime` module supplies classes for working with date and time, such as `date`, `time`, `datetime`, `timedelta`, and `timezone`.

2. **Importing**: You can import the module using `import datetime`.

3. **Common Classes**:
   - `date`: Represents a date (year, month, day) with no time or time zone.
   - `time`: Represents a time, independent of any particular day, with optional time zone information.
   - `datetime`: Combines a `date` and a `time`. It's the most commonly used class when you need both date and time attributes.
   - `timedelta`: Represents the difference between two dates or times.
   - `timezone`: Represents a fixed offset from the UTC (Coordinated Universal Time).

### The `datetime` Object

The `datetime` class is a combination of a date and a time, providing a comprehensive set of attributes and methods for manipulating datetime objects.

#### Attributes and Properties
- **Year, Month, Day**: Accessible via `datetime.year`, `datetime.month`, and `datetime.day`.
- **Hour, Minute, Second, Microsecond**: Accessible via `datetime.hour`, `datetime.minute`, `datetime.second`, and `datetime.microsecond`.
- **Timezone Information**: If present, accessible via `datetime.tzinfo`.

#### Key Methods
- **`today()`**: Returns the current local datetime with a timezone of `None`.
- **`now()`**: Similar to `today()` but provides an option to pass in a timezone.
- **`utcnow()`**: Returns the current UTC datetime.
- **`fromtimestamp(timestamp)`**: Creates a datetime object from a POSIX timestamp.
- **`strptime(date_string, format)`**: Parses a string into a datetime object based on a format string.
- **`strftime(format)`**: Formats a datetime object into a string.

#### Example Usage
```python
from datetime import datetime

# Current datetime
now = datetime.now()

# Accessing parts of the date
year = now.year
month = now.month
day = now.day

# Formatting datetime
formatted_date = now.strftime("%Y-%m-%d %H:%M:%S")
```

### The `timedelta` Object

The `timedelta` class is particularly useful for calculating differences in dates or times and for date manipulations, like adding or subtracting days, hours, minutes, or seconds from a datetime object.

#### Example Usage
```python
from datetime import datetime, timedelta

# Current datetime
now = datetime.now()

# Adding two days to the current datetime
new_date = now + timedelta(days=2)
```

### Practical Applications

1. **Date and Time Arithmetic**: Add or subtract specific time intervals from dates.
2. **Timezone Conversion**: Handle conversions between different timezones.
3. **Scheduling and Timers**: Calculate future or past dates for scheduling tasks.
4. **Data Timestamping**: Create and manipulate timestamps for data entries.

The `datetime` module is versatile and essential for any Python programmer dealing with dates and times, whether in web development, data science, automation, or any other domain.

---


### The `.split()` Method

The `.split()` method in Python is used to split a string into a list of substrings based on a specified delimiter.

#### Syntax
```python
str.split(separator, maxsplit)
```
- `separator` (optional): Specifies the delimiter to use for splitting the string. The default is any whitespace.
- `maxsplit` (optional): Specifies the maximum number of splits. The default value is -1, which means "all occurrences".

#### Examples

1. **Basic Splitting**
 
   ```python
   text = "hello world"
   words = text.split()
   print(words)  # Output: ['hello', 'world']
   ```
   This splits the string at spaces.

2. **Splitting with a Specific Separator**
 
   ```python
   data = "apple,banana,orange"
   fruits = data.split(',')
   print(fruits)  # Output: ['apple', 'banana', 'orange']
   ```
   Here, the string is split at each comma.

3. **Splitting with maxsplit**

   ```python
   sentence = "one two three four"
   words = sentence.split(' ', 2)
   print(words)  # Output: ['one', 'two', 'three four']
   ```
   This splits the string at the first two spaces only.

### Common Use Cases

- **Parsing Data**: Splitting strings is often used to parse data from files (like CSVs) or user input.
- **Text Processing**: In text analysis, splitting a string into words or sentences is a common first step.


---


### ```.get()``` Usage

In Python, the `.get()` method is commonly used with dictionaries. It allows you to access the value associated with a given key in a dictionary. The primary advantage of using `.get()` over the standard square bracket notation (`dict[key]`) is that it provides a way to handle cases where the key might not be present in the dictionary, thus avoiding a `KeyError`.

#### Basic Usage

The syntax of the `.get()` method is:
```python
value = dictionary.get(key, default_value)
```
- `key`: The key for which you want to retrieve the value.
- `default_value` (optional): The value to return if the key is not found. If not provided, `None` is returned by default.

#### Examples

##### 1. Basic Example
```python
my_dict = {'a': 1, 'b': 2, 'c': 3}
print(my_dict.get('b'))  # Outputs: 2
```

##### 2. Key Not Found, No Default Value
```python
print(my_dict.get('d'))  # Outputs: None
```
- If 'd' is not a key in `my_dict`, `None` is returned.

##### 3. Key Not Found, With Default Value
```python
print(my_dict.get('d', 4))  # Outputs: 4
```
- If 'd' is not found, it returns the default value `4`.

##### 4. Using `.get()` in a Conditional
```python
if my_dict.get('a') is not None:
    print("Key 'a' exists")
else:
    print("Key 'a' does not exist")
```
- This can be used to check if a key exists in the dictionary before performing an operation.

#### Using `.get()` vs Square Brackets

- **.get()**: 
  - Returns `None` or a specified default value if the key is not found.
  - Prevents the program from raising a `KeyError`.
- **Square Brackets (`dict[key]`)**: 
  - Raises a `KeyError` if the key is not found in the dictionary.

#### Conclusion
The `.get()` method is a safer approach when you are not sure if a key exists in the dictionary, as it allows you to avoid errors and handle missing keys gracefully. It is especially useful in data processing where dictionaries might have missing or optional keys.

---


No, you cannot directly replace `for key, value in my_dict.items():` with `for key, value in my_dict:` in Python when iterating over a dictionary. These two statements serve different purposes.

### Iterating Over a Dictionary with `.items()`

The statement `for key, value in my_dict.items():` is used to iterate over both keys and values in the dictionary. The `.items()` method returns a view of the dictionary’s key-value pairs, which allows you to unpack each pair into `key` and `value` variables within the loop.

#### Example
```python
my_dict = {'a': 1, 'b': 2, 'c': 3}
for key, value in my_dict.items():
    print(f"Key: {key}, Value: {value}")
```

### Iterating Over a Dictionary Without `.items()`

When you use `for key, value in my_dict:`, you'll encounter an error because iterating directly over a dictionary (`my_dict`) only gives you the keys, not the key-value pairs.

If you try to unpack the keys into two variables (`key` and `value`), Python will raise a `ValueError` as it expects to unpack an iterable of length 2, but instead, it finds a single element (the key).

#### Correct Usage Without `.items()`
```python
for key in my_dict:
    value = my_dict[key]
    print(f"Key: {key}, Value: {value}")
```

This way, you iterate over the keys of the dictionary and then access each corresponding value using `my_dict[key]`.

### Conclusion

While `for key, value in my_dict.items():` is the proper way to iterate over both keys and values, `for key in my_dict:` (without `.items()`) is used when you only need to iterate over the keys, accessing the values inside the loop if necessary.

---

Reversing a string in Python can be done in several ways, but one of the simplest and most common methods is to use slicing. Here's how you can do it:

### Using Slicing

```python
original_string = "Hello World"
reversed_string = original_string[::-1]
print(reversed_string)  # Output: "dlroW olleH"
```

In this example, `original_string[::-1]` creates a slice that starts from the end towards the first character, effectively reversing the string. The slice notation `[::-1]` works as follows:
- The first empty field before the first colon `:` means start at the end of the string.
- The second empty field after the first colon `:` means continue to the beginning of the string.
- The `-1` after the second colon `:` means the step size, here it indicates moving one step backward.

### Using the `reversed()` Function and `join()`

Another way to reverse a string is by using the `reversed()` function along with `join()`:

```python
reversed_string = ''.join(reversed(original_string))
print(reversed_string)  # Output: "dlroW olleH"
```

Here, `reversed(original_string)` returns an iterator that accesses the given string in the reverse order. The `join()` method then joins all the characters from this iterator into a new string.

Both methods are efficient and commonly used for string reversal in Python.

***

To store all characters of a string into a list in Python, you can simply convert the string into a list using the `list()` function. When a string is passed to `list()`, it automatically splits the string into a list of its individual characters.

Here's how you can do it:

```python
# Given string
string = "blue"

# Converting string to a list of characters
characters_list = list(string)

# The list now contains ['b', 'l', 'u', 'e']
print(characters_list)
```

This code will output `['b', 'l', 'u', 'e']`. Each character in the string "blue" is added as an element in the list without any spaces.

---

The `Counter` class from the `collections` module and the `accumulate` function from the `itertools` module in Python:

### Counter
`Counter` is a subclass of dictionary that is used to count hashable objects. It's a part of the `collections` module. Essentially, it's a collection where elements are stored as dictionary keys and their counts are stored as dictionary values.

#### Key Features:
- Counts the occurrences of each element in an iterable (like a list or tuple) or initializes from another mapping of elements to their counts.
- Provides a convenient way to tally occurrences of objects and can be used to implement algorithms that require frequency data.
- Supports various operations like addition, subtraction, intersection, and union.

#### Example Usage:
```python
from collections import Counter

# Example: Counting the occurrences of characters in a string
count = Counter("blueberry")
print(count)  # Counter({'b': 2, 'e': 2, 'r': 2, 'l': 1, 'u': 1, 'y': 1})
```

### accumulate
`accumulate` is a function in the `itertools` module that makes an iterator that returns accumulated sums, or accumulated results of other binary functions (specified via the optional `func` argument).

#### Key Features:
- By default, it calculates the accumulated sum.
- Can be used with any binary function passed as the `func` argument, not just addition.
- The accumulated result includes the initial item of the iterable.

#### Example Usage:
```python
import itertools

# Example: Accumulated sum
data = [1, 2, 3, 4, 5]
accumulated_sum = list(itertools.accumulate(data))
print(accumulated_sum)  # [1, 3, 6, 10, 15]

# Example: Accumulated product
import operator
accumulated_product = list(itertools.accumulate(data, operator.mul))
print(accumulated_product)  # [1, 2, 6, 24, 120]
```

Both `Counter` and `accumulate` are powerful tools in Python's standard library that offer efficient and elegant solutions for common tasks involving counting and accumulation operations.

---

The `map` function in Python is a built-in function that applies a specified function to each item of an iterable (like a list, tuple, etc.) and returns an iterator, which can be easily converted to another iterable like a list or tuple. It is often used for transforming data efficiently.

Here's the basic syntax:

```python
map(function, iterable)
```

- `function`: The function to execute for each item in the iterable.
- `iterable`: The iterable whose items are to be processed.

### Example Usage of `map`:

1. **Simple Transformation**: Applying a function to each item in a list.

   ```python
   def square(number):
       return number ** 2

   numbers = [1, 2, 3, 4, 5]
   squared_numbers = map(square, numbers)

   # Convert the result to a list
   squared_numbers = list(squared_numbers)
   print(squared_numbers)  # Output: [1, 4, 9, 16, 25]
   ```

2. **Using Lambda Functions**: Often used with `map` for concise transformations.

   ```python
   numbers = [1, 2, 3, 4, 5]
   squared_numbers = map(lambda x: x**2, numbers)

   # Convert to list and print
   print(list(squared_numbers))  # Output: [1, 4, 9, 16, 25]
   ```

3. **Multiple Iterables**: The function can take as many arguments as there are iterables.

   ```python
   numbers1 = [1, 2, 3]
   numbers2 = [4, 5, 6]
   result = map(lambda x, y: x + y, numbers1, numbers2)

   # Convert to list and print
   print(list(result))  # Output: [5, 7, 9]
   ```

4. **Using Built-in Functions**: `map` can also be used with built-in functions.

   ```python
   strings = ["hello", "world"]
   lengths = map(len, strings)

   # Convert to list and print
   print(list(lengths))  # Output: [5, 5]
   ```

### Key Points:

- `map` returns an iterator, so you often need to wrap it with `list()`, `set()`, etc., to get the transformed data in a desired format.
- It's especially useful for concise, readable code for simple data transformations.
- In Python 3.x, `map` is lazy, meaning it only produces the elements as they are needed. This can be efficient for large datasets.
- For more complex transformations, list comprehensions or generator expressions might be more readable.

---

To sort a dictionary in Python by its values, you can use the `sorted()` function along with a key argument. The `sorted()` function doesn't sort the dictionary itself (since dictionaries are inherently orderless up to Python 3.6 and maintain insertion order in Python 3.7+), but it can be used to produce a sorted representation of the dictionary.

Here's how you can sort a dictionary by its values:

### Sorting into a List of Tuples

If you just need a sorted list of tuples (where each tuple is a key-value pair from the dictionary):

```python
my_dict = {'a': 3, 'b': 1, 'c': 2}

sorted_tuples = sorted(my_dict.items(), key=lambda item: item[1])

print(sorted_tuples)  # Output: [('b', 1), ('c', 2), ('a', 3)]
```

Here, `my_dict.items()` returns a view of the dictionary's items (key-value pairs), and `sorted()` sorts these items based on the value (the second element of each tuple, accessed with `item[1]`).

### Sorting into a New Dictionary

If you want a new dictionary that maintains this order (Python 3.7+), you can convert the sorted list of tuples back into a dictionary:

```python
sorted_dict = dict(sorted(my_dict.items(), key=lambda item: item[1]))

print(sorted_dict)  # Output: {'b': 1, 'c': 2, 'a': 3}
```

In this case, `sorted_dict` is a dictionary that maintains the order of the elements as they were sorted.

### Reverse Sorting

If you want to sort in descending order, you can set the `reverse` parameter to `True`:

```python
sorted_dict_desc = dict(sorted(my_dict.items(), key=lambda item: item[1], reverse=True))

print(sorted_dict_desc)  # Output: {'a': 3, 'c': 2, 'b': 1}
```

These methods are the most common ways to sort a dictionary by its values in Python. Remember that sorting by values makes the most sense when the values are comparable types (like numbers or strings).

---

The `bisect_right` function in Python is part of the `bisect` module, which provides support for maintaining a list in sorted order without having to sort the list after each insertion. Specifically, `bisect_right` is used for binary searching a sorted list to find the insertion point for a specified element.

Here's how to use `bisect_right`:

1. **Import bisect Module**: First, you need to import the `bisect` module.

2. **Using bisect_right**: The function `bisect.bisect_right(a, x, lo=0, hi=len(a))` locates the insertion point for `x` in `a` to maintain sorted order. If `x` is already present in `a`, the insertion point will be after (to the right of) any existing entries. The parameters `lo` and `hi` may be used to specify a subset of the list which should be considered.

### Basic Example

```python
import bisect

# Create a sorted list
sorted_list = [1, 3, 4, 4, 5, 7, 9]

# Find the index to insert a new element to maintain the sorted order
index = bisect.bisect_right(sorted_list, 4)

print(f"The rightmost index to insert, so the list remains sorted: {index}")
```

In this example, `bisect_right` will return `4`. This means that the number `4` should be inserted at index `4` to maintain the sorted order (after the existing `4`s in the list).

### Difference between `bisect_right` and `bisect_left`

`bisect` module also provides a similar function called `bisect_left`. The difference is:

- `bisect_left`: Returns the leftmost place in the sorted list to insert the given element — so the element would be inserted *before* any existing entries with the same value.
- `bisect_right`: Returns the rightmost place to insert — so the element would be inserted *after* any existing entries with the same value.

### Use Cases

- **Maintaining a Sorted List**: For dynamically maintaining a list in sorted order without re-sorting the list each time when a new element is inserted.
- **Searching**: To quickly find the index of an element or determine where to insert a new element to maintain order.

Remember, for `bisect_right` to work correctly, the input list `a` must already be sorted.

---

Python offers several built-in methods related to letters and the alphabet, primarily as part of its string methods. Here's a list of some of the most commonly used string methods that are directly relevant to handling letters and the alphabet:

1. **`isalpha()`**: Returns `True` if all characters in the string are alphabetic (a-z, A-Z) and there is at least one character, otherwise `False`.

2. **`isalnum()`**: Returns `True` if all characters in the string are alphanumeric (a combination of alphabets and numbers).

3. **`isdigit()`**: Returns `True` if all characters in the string are digits, otherwise `False`.

4. **`islower()`**: Returns `True` if all cased characters in the string are lowercase and there is at least one cased character, otherwise `False`.

5. **`isupper()`**: Returns `True` if all cased characters in the string are uppercase and there is at least one cased character, otherwise `False`.

6. **`istitle()`**: Returns `True` if the string is a titlecased string (where each word starts with an uppercase letter followed by lowercase letters).

7. **`lower()`**: Returns a copy of the string converted to lowercase.

8. **`upper()`**: Returns a copy of the string converted to uppercase.

9. **`capitalize()`**: Returns a copy of the string with its first character capitalized and the rest lowercased.

10. **`title()`**: Returns a titlecased version of the string where words start with an uppercase character and the remaining characters are lowercase.

11. **`swapcase()`**: Returns a string where all the lowercase letters are converted to uppercase, and the uppercase letters are converted to lowercase.

12. **`startswith()`**: Returns `True` if the string starts with the specified prefix (which can be a letter or group of letters), otherwise `False`.

13. **`endswith()`**: Returns `True` if the string ends with the specified suffix (which can be a letter or group of letters), otherwise `False`.

14. **`find()` / `rfind()`**: Returns the lowest index (or highest index in the case of `rfind`) in the string where the specified substring is found. This can be used to locate letters or sequences of letters within a string.

15. **`index()` / `rindex()`**: Similar to `find()` / `rfind()`, but raise a `ValueError` when the substring is not found.

16. **`replace()`**: Returns a string where a specified value is replaced with a specified value, which can be used to replace letters or groups of letters.

17. **`count()`**: Returns the number of times a specified value (which can be a letter or group of letters) occurs in the string.

18. **`strip()` / `rstrip()` / `lstrip()`**: These methods are used to remove whitespaces or specified characters from the beginning and/or end of a string. They can be used to remove letters from the ends of a string.

These methods are part of the standard string class in Python and are used for various operations involving text manipulation and inspection. Remember, these methods are case-sensitive, and they only operate on strings.

---