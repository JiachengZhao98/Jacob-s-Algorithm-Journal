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