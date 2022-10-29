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
