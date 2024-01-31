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
+ [Linux Command](#Linux)


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

In C++, a priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction. A user-provided `Compare` function determines the priority of elements. By default, this is a max heap (where the largest element is given the highest priority), but it can be made into a min heap (where the smallest element is given the highest priority) by providing a custom comparison function.

Here are some key points about priority queues in C++:

1. **Underlying Container:** The `std::priority_queue` is implemented using a container, usually a vector or a deque, and organizes its elements in a heap structure. The element at the "top" of the heap is the one with the highest priority.

2. **Default Behavior:** By default, the C++ priority queue uses the `std::less` comparator, creating a max heap where the element with the greatest value is always at the top.

3. **Custom Comparator:** You can provide a custom comparator to change the ordering. For instance, using `std::greater` would turn it into a min heap.

4. **Main Operations:**
   - `push`: Insert an element into the queue. The insertion is logarithmic in complexity.
   - `pop`: Remove the top element from the queue. This operation is also logarithmic in complexity.
   - `top`: Access the top element in the queue. This operation is constant in complexity.

5. **No Direct Access to Elements:** Unlike a standard queue, you can't iterate through the elements of a priority queue. You only have access to the top element.

6. **Usage:** Priority queues are often used in algorithms where the order of processing elements is critical, such as Dijkstra's algorithm for shortest paths, or in systems where tasks are prioritized (like an operating system's task scheduler).

Here's a simple example of using a priority queue in C++:

```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Adding elements
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // This will print elements in descending order
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

This code snippet creates a max heap priority queue, adds some elements, and then removes them in descending order.

---

In C++, `sum()` and `accumulate()` are two different functions used for calculating the sum of elements in a range, but they belong to different parts of the standard library and have some key differences:

1. **Library and Availability:**
   - `accumulate()`: It's part of the `<numeric>` header. This function has been available since C++98.
   - `sum()`: This function is introduced in C++20 as part of the `<numeric>` header. It's a newer addition to the standard library.

2. **Syntax and Usage:**
   - `accumulate()`:
     ```cpp
     accumulate(InputIterator first, InputIterator last, T init, BinaryOperation op);
     ```
     - `first`, `last`: Iterators specifying the range.
     - `init`: Initial value for the accumulation.
     - `op`: Binary operation function that will be applied. It's optional and defaults to addition.
   - `sum()`:
     ```cpp
     sum(InputIterator first, InputIterator last);
     ```
     - `first`, `last`: Iterators specifying the range.
     - Note: There's no initial value or custom operation; it's purely for summing the elements.

3. **Functionality:**
   - `accumulate()` is more flexible. It not only sums the elements but can also perform other operations if a custom binary operation is provided. It can start from an initial value other than zero.
   - `sum()`, on the other hand, is designed specifically for summing up elements. It always starts from zero and does not support custom operations.

4. **Performance:**
   - `sum()` might offer better performance for summing elements, especially in C++20 and later, as it is specifically optimized for this operation.
   - `accumulate()`, being more generic and versatile, might have slight overhead when used for complex custom operations.

5. **Use Cases:**
   - Use `accumulate()` when you need a generalized reduction (like products, logical AND/OR, etc.) or when working with versions of C++ before C++20.
   - Use `sum()` when you specifically need to sum elements and are using C++20 or later.

In summary, `accumulate()` is a versatile function suitable for various accumulation operations, including but not limited to summing, while `sum()` is a specialized function introduced in C++20 specifically optimized for summing the elements of a range.

---

If you're working with a 2D vector in C++ and want to extract a part of it, the approach is similar to working with a 1D vector, but you need to consider both dimensions. Here's how you can do it:

### Extracting a Sub-2D-Vector

Suppose you have a 2D vector (a vector of vectors) and you want to extract a sub-2D-vector defined by specific row and column ranges. You would iterate through the selected rows and columns to create this new sub-2D-vector.

Here's an example to illustrate this:

```cpp
#include <iostream>
#include <vector>

int main() {
    // Example 2D vector
    std::vector<std::vector<int>> vec2D = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Define row and column ranges for the sub-vector
    int startRow = 1, endRow = 3; // Selecting rows 1 to 2 (0-based index, end exclusive)
    int startCol = 1, endCol = 3; // Selecting columns 1 to 2 (0-based index, end exclusive)

    // Create the sub-2D-vector
    std::vector<std::vector<int>> subVec2D;
    for (int i = startRow; i < endRow; ++i) {
        std::vector<int> subRow(vec2D[i].begin() + startCol, vec2D[i].begin() + endCol);
        subVec2D.push_back(subRow);
    }

    // Displaying the sub-2D-vector
    for (const auto &row : subVec2D) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

In this example:
- `vec2D` is your original 2D vector.
- `subVec2D` is the extracted sub-2D-vector.
- The row range is from `startRow` to `endRow-1` and the column range is from `startCol` to `endCol-1`.

### Points to Note

- Ensure that the specified row and column ranges are within the bounds of the original 2D vector to avoid undefined behavior.
- This method copies the selected parts of the original 2D vector into a new 2D vector. If your 2D vector is large, consider the implications on memory usage and performance.

---

In C++, you can access a specific character in a string based on its index using the subscript operator (`[]`). If you want to get a substring from a string starting at a particular index, you can use the `substr` method. Here's how to use both:

1. **Accessing a Specific Character by Index:**
   ```cpp
   std::string str = "Hello, World!";
   char ch = str[index]; // Replace 'index' with the position you want.
   ```

2. **Getting a Substring Starting at a Specific Index:**
   To get a substring from a string starting at a particular index, you can use the `substr` function. The `substr` function takes two parameters: the starting index and the length of the substring. If the length is not specified, it takes the rest of the string by default.
   
   ```cpp
   std::string str = "Hello, World!";
   std::string substring = str.substr(startIndex); // Takes the rest of the string from startIndex.
   std::string anotherSubstring = str.substr(startIndex, length); // Takes 'length' characters from startIndex.
   ```

   In the above example, replace `startIndex` with the starting index of the substring and `length` with the number of characters you want in the substring.

Remember, string indexing in C++ starts at 0, so the first character is at index 0, the second character is at index 1, and so on. If you use an index that is out of the bounds of the string (either negative or greater than or equal to the string's length), it will result in undefined behavior.

---

### `Heap`

A heap is a specialized **tree-based** data structure that satisfies the heap property. In the context of computer science, there are two types of heaps: a max heap and a min heap.

1. **Max Heap**: In a max heap, for any given node I, the value of I is greater than or equal to the values of its children. The highest (maximum) value is at the root.

2. **Min Heap**: In a min heap, for any given node I, the value of I is less than or equal to the values of its children. The lowest (minimum) value is at the root.

Here are some key characteristics of heaps:

- **Complete Binary Tree**: A heap is a complete binary tree, which means all levels of the tree are fully filled except possibly the last level, which is filled from left to right.

- **Heap Property**: This is the property that defines the order of the nodes. As mentioned, in a max heap, parent nodes have values greater than or equal to their children, while in a min heap, they have values less than or equal to their children.

- **Implementation**: Heaps are usually implemented using arrays. The array representation is possible because heaps are complete binary trees. If the parent is at index `i`, the left child can be calculated by `2 * i + 1` and the right child by `2 * i + 2`.

- **Efficiency**: Heaps provide efficient implementation of priority queues. Operations like insertion, deletion, and accessing the top element (maximum or minimum) are performed in O(log n) time, where n is the number of elements in the heap.

- **Heap Operations**: The basic operations include `insertion` (adding a new key), `heapify` (regaining heap properties after insertion or deletion), `deletion` (removing the root, in max heaps this is the maximum element and in min heaps this is the minimum element), and `peek` (accessing the top element without removing it).

- **Usage**: Heaps are used in various algorithms like heap sort, and for creating priority queues. They are also useful in applications like implementing Dijkstra's algorithm for shortest path, in Huffman coding for data compression algorithms, etc.

In programming languages like C++, the Standard Library provides a heap functionality through the `priority_queue` container adapter, where by default it acts as a max heap, but can be customized to work as a min heap. Python provides a `heapq` module for implementing heaps, which by default creates a min heap.

---

### `std::priority_queue`

In C++, `std::priority_queue` is a container adapter that **provides constant time lookup of the largest (by default) element**, at the expense of logarithmic insertion and extraction. A specific property of this container is that it's not a sequence container like `vector` or `list`, but rather a container adapter that uses an underlying container to provide a specific set of operations.

Here's a basic overview of how to use `std::priority_queue`:

1. **Header File**: To use `std::priority_queue`, you need to include the header file `queue`.

   ```cpp
   #include <queue>
   ```

2. **Declaration**: You can declare a `priority_queue` like this:
   ```cpp
   std::priority_queue<int> pq;
   ```
   This declares a max-heap `priority_queue` of integers.

3. **Custom Comparator**: If you want a min-heap or a custom order, you need to declare it with a custom comparator.
   ```cpp
   std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
   ```
   This creates a min-heap for integers.

4. **Inserting Elements**: Use `push` to insert elements.
   ```cpp
   pq.push(10);
   pq.push(5);
   pq.push(20);
   ```

5. **Accessing the Top Element**: The top of the priority queue (the largest element in a max-heap or the smallest in a min-heap) can be accessed using `top`.
   ```cpp
   int topElement = pq.top();
   ```

6. **Removing Elements**: To remove the top element, use `pop`. This removes the element but does not return it.
   ```cpp
   pq.pop();
   ```

7. **Size and Empty Check**: Like other standard containers, `priority_queue` supports `empty()` and `size()` methods.
   ```cpp
   bool isEmpty = pq.empty();
   size_t size = pq.size();
   ```

8. **Underlying Container Customization**: `std::priority_queue` allows you to specify an underlying container. By default, it uses `std::vector`. You can specify a different container like `std::deque` if needed.

Here is a simple example:

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

    // Inserting elements
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);

    // Printing and removing elements
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

In this example, the output will be in descending order (50, 40, 30, 20), as the default behavior of `std::priority_queue` is to create a max-heap.

The `std::priority_queue` in C++ is a container adapter, which means it provides a specific interface on top of an underlying container. The key characteristics of `std::priority_queue`'s implementation are:

1. **Underlying Container**: By default, `std::priority_queue` uses a `std::vector` as its underlying container, but it can be configured to use other containers like `std::deque`. The requirement for the underlying container is that it must support random access iterators, `front()`, `push_back()`, and `pop_back()` operations.

2. **Heap Structure**: The elements in the `priority_queue` are internally organized in a heap structure. For a max heap (default behavior), the largest element is kept at the top (beginning of the underlying container), and for a min heap (when using a custom comparator), the smallest element is at the top.

3. **Operations**:
   - **Insertion (`push`)**: When a new element is added, it is initially inserted at the end of the underlying container (like a regular vector insertion). Then, a heap adjustment is performed by "bubbling up" the element to its correct position in the heap. This is typically done using the `std::push_heap` algorithm and takes O(log n) time.
   - **Removal (`pop`)**: To remove the top element (the largest for max heap, or smallest for min heap), the heap algorithm swaps the first element with the last one in the underlying container, then it removes the last element (actual removal from the container). After this, the heap property is restored by "sifting down" the new first element. This uses the `std::pop_heap` algorithm and also takes O(log n) time.
   - **Accessing Top Element (`top`)**: This operation simply returns the first element in the underlying container, which is the largest (or smallest) element due to the heap property. This operation is O(1).

4. **Custom Comparator**: You can change the ordering by providing a custom comparator while declaring the `priority_queue`. For example, using `std::greater<T>` will create a min heap.

5. **No Direct Access to Elements**: Unlike `std::vector` or `std::deque`, you cannot directly access elements in a `priority_queue` other than the top element. The `priority_queue` interface intentionally hides the underlying container's operations that could potentially violate the heap property.

Here's a simple illustrative example:

```cpp
#include <queue>
#include <vector>
#include <functional> // for std::greater

int main() {
    // Max heap (default)
    std::priority_queue<int> maxHeap;

    // Min heap using std::greater
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    // ... Operations like push, pop, top
}
```

In practice, this means that `std::priority_queue` is a very efficient way to implement a max-heap or min-heap without needing to manually maintain the heap property, as the standard library algorithms do this automatically.

---

Yes, there are alternative methods to sort elements in descending order in C++ without explicitly defining a custom comparator like a lambda function. One common approach is to use the `std::greater<>` comparator from the `<functional>` header. This is a predefined function object that applies the greater-than operator (`>`) to two values.

Here's an example using `std::sort` with `std::greater<>` to sort a vector of integers in descending order:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // For std::greater

int main() {
    std::vector<int> vec = {4, 1, 3, 5, 2};

    // Sorting in descending order using std::greater<>
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // Printing the sorted vector
    for(int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
```

In this example, `std::greater<int>()` is used as the comparator for `std::sort`. It automatically applies the greater-than operator to pairs of elements in the vector, resulting in a sorted vector in descending order. This method is cleaner and more readable, especially when dealing with primitive data types like integers, floats, or strings.

Additionally, if you're working with C++14 or later, you can use `std::greater<>` without specifying the template argument, as it will be deduced automatically:

```cpp
std::sort(vec.begin(), vec.end(), std::greater<>());
```

This feature is known as template argument deduction for function templates (introduced in C++14), which makes the code even more concise.

---

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
In Python, a heap is a specialized tree-based data structure that satisfies the heap property. In a heap, for any given node `i`, the value of `i` is greater than or equal to the values of its children (in a max heap) or less than or equal to the values of its children (in a min heap). The most common type of heap is a binary heap, where each node has at most two children.

Python's standard library provides the `heapq` module, which implements a min heap on top of a regular list with functions to maintain the heap property. Here's a brief overview of how to use the `heapq` module:

1. **Creating a Heap**: A heap is created by using a list. The `heapq` module provides functions like `heapify`, which converts a list into a heap.

   ```python
   import heapq

   # Creating a heap
   my_heap = [3, 1, 4, 1, 5, 9, 2, 6, 5]
   heapq.heapify(my_heap)  # Transforms the list into a heap
   ```

2. **Adding Elements**: Use `heapq.heappush()` to add elements to the heap. This function maintains the heap property.

   ```python
   heapq.heappush(my_heap, 7)
   ```

3. **Removing Elements**: The `heapq.heappop()` function removes and returns the smallest element from the heap.

   ```python
   smallest_element = heapq.heappop(my_heap)
   ```

4. **Accessing the Smallest Element**: The smallest element in the heap can be accessed as `my_heap[0]`. This does not remove the element from the heap.

5. **Converting to Max Heap**: Python's `heapq` implements a min heap. To create a max heap, you can invert the values during the push and pop operations.

   ```python
   # For max heap, insert negative values
   heapq.heappush(my_heap, -element)

   # Retrieve the values by negating again
   largest_element = -heapq.heappop(my_heap)
   ```

6. **Other Functions**: `heapq` also provides `heapreplace`, `nlargest`, `nsmallest`, and more, offering additional functionality for working with heaps.

Heaps are commonly used in algorithms that require frequent retrieval of the smallest (or largest) element, such as in sorting algorithms (Heap Sort), and for implementing priority queues.

---

Reversing the order of all elements in a list in Python can be done in several ways:

1. **Using the `reverse()` method**: This method modifies the list in place and reverses the elements of the list.

   ```python
   my_list = [1, 2, 3, 4, 5]
   my_list.reverse()
   print(my_list)  # Output: [5, 4, 3, 2, 1]
   ```

2. **Using slicing**: This method creates a new list that is a reversed copy of the original list.

   ```python
   my_list = [1, 2, 3, 4, 5]
   reversed_list = my_list[::-1]
   print(reversed_list)  # Output: [5, 4, 3, 2, 1]
   ```

   The `[::-1]` slicing works by starting at the end of the list and stepping backwards.

3. **Using the `reversed()` function**: This function returns an iterator that accesses the given sequence in the reverse order. You can convert this iterator to a list if you need a list object.

   ```python
   my_list = [1, 2, 3, 4, 5]
   reversed_list = list(reversed(my_list))
   print(reversed_list)  # Output: [5, 4, 3, 2, 1]
   ```

Each of these methods can be used depending on whether you need to reverse the list in place or create a reversed copy of it.

---

In Python, which is an interpreted language, the concepts of run-time and compile-time can be a bit different compared to traditional compiled languages like C or Java. Here's a brief overview of both terms in the context of Python:

1. **Compile-Time**:
   - **Bytecode Compilation**: Python code is first compiled into bytecode, which is a lower-level, platform-independent representation of your source code. This happens before the code is run. The Python interpreter compiles the code to bytecode, and this is typically when syntax errors are caught.
   - **Early Error Checking**: During this phase, Python performs some basic checks, such as syntax parsing, checking for indents, and interpreting the structure of the code. If there are syntax errors, the script will fail to compile to bytecode and the execution will stop.
   - **Optimizations**: Some minor optimizations are also done during this phase, but they are not as extensive as in languages like C++ or Java.
   
   Python's compile-time phase is relatively simpler compared to compiled languages because a lot of checks (like type checking) are deferred to the run-time phase.

2. **Run-Time**:
   - **Bytecode Execution**: After the code is compiled into bytecode, it is then executed by the Python Virtual Machine (PVM). This is the run-time phase.
   - **Type Checking and Error Handling**: Python is dynamically typed, so type checking is done at run-time. This means that errors like type errors or name errors (referencing a variable that has not been defined) are detected during run-time.
   - **Memory Management**: Python handles memory allocation and garbage collection during run-time.
   - **Late Binding**: Functions and variables are bound at run-time, providing flexibility but also meaning that certain errors are not caught until the program is actually running.
   - **Execution of Code**: Finally, this is the phase where your code actually performs its operations – calculations, I/O operations, data manipulation, etc.

In summary, compile-time in Python is about converting source code to bytecode and catching syntax-related errors, while run-time encompasses type checking, memory management, and the actual execution of the compiled bytecode. The distinction between compile-time and run-time in Python is less pronounced than in strictly compiled languages, due to its dynamic and interpreted nature.

---

### List comprehension

List comprehension is a concise and efficient way to create lists in Python. It provides a more readable and expressive way to create lists compared to traditional loops and list-building techniques. The basic structure of a list comprehension is:

```python
[expression for item in iterable if condition]
```

Here's a breakdown of the components:

1. **`expression`**: This is the value to be added to the resulting list. It is usually a function of `item`.

2. **`for item in iterable`**: This is a `for` loop over an iterable (like a list, tuple, range, string, etc.). `item` takes on each value in the iterable.

3. **`if condition`** (optional): A condition to filter items from the iterable. Only items for which the condition evaluates to `True` are included in the new list.

### Examples

1. **Basic List Comprehension**:
   - Create a list of squares for numbers 0 through 9.
     ```python
     squares = [x**2 for x in range(10)]
     print(squares)  # Output: [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
     ```

2. **List Comprehension with `if` Condition**:
   - Create a list of even numbers from 0 to 9.
     ```python
     evens = [x for x in range(10) if x % 2 == 0]
     print(evens)  # Output: [0, 2, 4, 6, 8]
     ```

3. **Nested List Comprehension**:
   - Create a flattened list from a list of lists.
     ```python
     matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
     flat = [num for row in matrix for num in row]
     print(flat)  # Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
     ```

4. **List Comprehension with Complex Expressions**:
   - Convert a list of temperatures in Celsius to Fahrenheit.
     ```python
     celsius = [0, 10, 20, 30]
     fahrenheit = [((9/5) * temp + 32) for temp in celsius]
     print(fahrenheit)  # Output: [32.0, 50.0, 68.0, 86.0]
     ```

List comprehensions are not only about creating lists; they embody the functional programming style often found in Python, encouraging you to think in terms of sequences, transformations, and filters. However, it's important to use them judiciously; very complex list comprehensions can become difficult to read and understand, defeating their purpose of simplifying code.

---

A lambda function in Python is a small, anonymous function defined using the keyword `lambda`. Lambda functions can take any number of arguments but can only have one expression. They are often used in situations where a simple function is required for a short duration, without the need to formally define a function using the standard `def` keyword.

The general syntax of a lambda function is:

```python
lambda arguments: expression
```

Here, `arguments` is a list of parameters (like `x`, `y`), and `expression` is an expression that is evaluated and returned. This expression is executed when the lambda function is called.

### Key Characteristics:

1. **Anonymous**: They are not declared in the standard manner by using the `def` keyword. You can use them without having to assign a name.

2. **Inline**: Lambda functions are typically used where they are needed, often as an argument to a higher-order function (a function that takes in other functions as arguments).

3. **Single Expression**: Unlike a regular function, they can only have a single expression, which is evaluated and returned.

### Examples:

1. **Simple Lambda Function**:
   ```python
   add = lambda x, y: x + y
   print(add(5, 3))  # Output: 8
   ```

2. **Lambda Function as an Argument**:
   - Using a lambda function with the `sorted` function.
     ```python
     points = [(1, 2), (3, 3), (5, 1)]
     points_sorted = sorted(points, key=lambda point: point[1])
     print(points_sorted)  # Output: [(5, 1), (1, 2), (3, 3)]
     ```

3. **Lambda Function in `map()`**:
   - Using a lambda function to square each number in a list.
     ```python
     nums = [1, 2, 3, 4]
     squared = list(map(lambda x: x**2, nums))
     print(squared)  # Output: [1, 4, 9, 16]
     ```

4. **Lambda Function in `filter()`**:
   - Using a lambda function to filter out even numbers.
     ```python
     nums = [1, 2, 3, 4, 5, 6]
     evens = list(filter(lambda x: x % 2 == 0, nums))
     print(evens)  # Output: [2, 4, 6]
     ```

Lambda functions are a convenient feature of Python, particularly useful for short, throwaway functions that are not reused elsewhere in your code. However, they are limited by their simplicity and should be used sparingly for the sake of code readability. For more complex functionalities, a regular function defined with `def` is preferred.

---

Exception handling in Python is done using the `try`, `except`, `else`, and `finally` blocks. These blocks allow you to gracefully handle errors and exceptions that occur during the execution of a program, preventing the program from crashing and providing a user-friendly way to deal with unexpected issues.

Here's a brief overview of each of these blocks:

1. **`try` Block**: 
   - This is where you write the code that you think might raise an exception. The code inside the `try` block is executed first.

2. **`except` Block**:
   - If an exception occurs in the `try` block, the flow of control immediately passes to the `except` block.
   - You can specify the type of exception you want to catch. If you don't specify any exception, it catches all exceptions, which is not recommended due to potential unintended side effects.
   - You can have multiple `except` blocks to handle different exceptions differently.

3. **`else` Block** (optional):
   - The `else` block is executed if no exception is raised in the `try` block.
   - This is useful for code that should only run if the `try` block did not throw an exception.

4. **`finally` Block** (optional):
   - This block is executed no matter what, whether an exception is raised or not. It's typically used for cleanup actions, such as closing files or releasing resources.

### Example:

```python
try:
    # Code that might raise an exception
    result = 10 / 0
except ZeroDivisionError:
    # Handling a specific exception
    print("You can't divide by zero!")
except Exception as e:
    # Catching any other exceptions
    print(f"An error occurred: {e}")
else:
    # Runs if the try block is successful
    print("Operation successful")
finally:
    # Always runs
    print("Execution complete")
```

In this example, the `ZeroDivisionError` is specifically caught and handled. The generic `except` block catches any other exceptions that might occur. The `else` block would run if there was no exception, and the `finally` block runs in any case, ensuring that the message "Execution complete" is printed whether an exception occurs or not.

Proper exception handling is essential for writing robust and error-tolerant programs in Python. It helps to ensure that your program can deal with unexpected situations gracefully without crashing abruptly.

---

## Linux Command <a name="Linux"></a>

### Basic Linux Command Cheat Sheet

#### File Operations
- `ls`: List directory contents.
- `cd [directory]`: Change the current directory.
- `pwd`: Display the current directory path.
- `cp [source] [destination]`: Copy files or directories.
- `mv [source] [destination]`: Move/rename files or directories.
- `rm [file]`: Remove files (use `-r` for directories).
- `touch [file]`: Create a new empty file.
- `mkdir [directory]`: Create a new directory.
- `rmdir [directory]`: Delete an empty directory.

#### File Viewing & Editing
- `cat [file]`: Display file content.
- `less [file]`: View file content in an interactive mode.
- `nano [file]`: Edit file using the Nano editor.
- `vi [file]`: Edit file using the Vi editor.

#### System Information & Management
- `top`: Display system processes and resource usage.
- `df`: Show disk usage.
- `free`: Display memory usage.
- `uptime`: Show system uptime.
- `uname -a`: Display system information.

#### Networking
- `ping [address]`: Check the network connection to an address.
- `ifconfig`: Display network interfaces and IP addresses.
- `netstat`: Display network connections, routing tables, etc.

#### File Permissions
- `chmod [permissions] [file]`: Change file permission.
- `chown [owner] [file]`: Change file owner.
- `chgrp [group] [file]`: Change file group.

#### Package Management (Debian-based systems)
- `sudo apt-get update`: Update package list.
- `sudo apt-get upgrade`: Upgrade all packages.
- `sudo apt-get install [package]`: Install a new package.
- `sudo apt-get remove [package]`: Remove an installed package.

#### Archiving and Compression
- `tar -cvf [archive.tar] [file]`: Create a tar archive.
- `tar -xvf [archive.tar]`: Extract a tar archive.
- `gzip [file]`: Compress a file.
- `gunzip [file.gz]`: Decompress a file.

#### Searching Files and Directories
- `find [directory] -name [filename]`: Find files by name.
- `grep [text] [file]`: Search for text within a file.

#### Process Management
- `ps`: Display current processes.
- `kill [pid]`: Terminate a process by its PID.
- `killall [processname]`: Terminate all processes with the given name.

#### System Shutdown & Reboot
- `shutdown now`: Shutdown the system immediately.
- `reboot`: Reboot the system.

This cheat sheet covers basic operations and is suitable for beginners. For advanced operations and more detailed options, you may want to refer to the man pages (`man [command]`) or online resources dedicated to specific commands.

### Searching for a specific keyword or partial argument in the history of commands

1. **Using the `history` command with `grep`:**
   - The `history` command in Linux shows you a list of the commands you've entered in the past.
   - You can combine `history` with `grep` to search for a specific keyword. For example, if you remember a part of the command was `file.txt`, you would use:
     ```bash
     history | grep file.txt
     ```
   - This command will display all instances in your command history where `file.txt` was mentioned.

2. **Incremental Search in the Terminal:**
   - Most Linux terminals support incremental search. You can initiate this by pressing `Ctrl` + `R` and then start typing the part of the command you remember.
   - As you type, the terminal will dynamically search your command history and show the most recent command that matches the text you've entered.
   - You can press `Ctrl` + `R` repeatedly to cycle through older matching commands.

3. **Using `!` to Recall Commands:**
   - If you remember the first few characters of a command, you can use the `!` feature. For example, if your command started with `ls`, you can type `!ls`, and it will execute the most recent command that started with `ls`.
   - Note that this method directly executes the command, so use it with caution, especially if the command could potentially be destructive.

4. **Checking Your Shell's History File:**
   - The commands you enter are typically stored in a history file in your home directory. For bash, this is usually `.bash_history`.
   - You can view this file using a text editor or by using commands like `cat` or `less` to see your command history. For example:
     ```bash
     less ~/.bash_history
     ```

5. **Extending History Size:**
   - If you find your history isn't going back far enough, you might need to increase the size of your command history. This can be done by setting the `HISTSIZE` and `HISTFILESIZE` variables in your shell's configuration file (like `.bashrc` for bash).

These methods should help you locate and recall previously used commands in Linux, even if you only remember a part of them.

---

