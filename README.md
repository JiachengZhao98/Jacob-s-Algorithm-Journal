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

1. [CPP](#CPP)
2. [Java](#Java)
3. [Python](#Python)

---

### CPP <a name="CPP"></a>
#### Vector
+ The usage of a 2-D vector ➡️ [click here](https://www.digitalocean.com/community/tutorials/2d-vectors-in-c-plus-plus) 

+ About built-in sorting function for vector:```vector.sort()```:
	- The C++ standard specifies that the worst-case runtime of std::sort() is in O(n log n)
	-  the usage for the third argument:
		- ``` bool myfunction (int i,int j) { return (i<j); } //acending ```
		- ```bool myfunction2 (int i,int j) { return (i>j); }  //desending ```
		- ```static bool cmp(int a, int b) {return abs(a) > abs(b); // desending based on absolute values} ```


+ pay more attention to the value of **i** when using the *for* loop, 'cause when one loop is down **i** will ++


+ how to get the number of rows and columns from a 2-D vector:
	+ ```int size_row = vec.size();  //acquire the number of row ```
	+ ``` int size_col = vec[0].size();  //acquire the number of column```
	
 
+ how to round the output into two digits ( just remember the code below is enough...):

``` 
#include<iomanip>  //header file
cout<<setiosflags(ios::fixed)<<setprecision(2);
```

+ ``` vector::resize(int n, int val)```
The function alters the container’s content in actual by inserting or deleting the elements from it. It happens so,
If the given value of n is less than the size at present then extra elements(at the END of the vector) are demolished.
If n is more than current size of container then upcoming elements are appended at the end of the vector.

+ Vector Initialization: 
	+ Example:
	
	```
	vector<int> ilist1; // first way
	vector<int> ilist2(ilist1);  // second way
	vector<int> ilist3  = ilist1; // third way
	// ilist1, ilist2 and ilist3 are all the SAME !!!
	```

 vector<int> ilist = {1,2,3.0,4,5,6,7};
       vector<int> ilist {1,2,3.0,4,5,6,7};
If met some values that are not int, this func will automatically change the value type. 

 vector<int> ilist3(ilist.begin()+2,ilist.end()-1); //e.g. ilist3 = {3, 4, 5, 6} 
// the vector only copies to the front value of the second value input

 vector<int> ilist4(7); // this vector will contain 7 values, which are not initialized. 

 vector<int> ilist5(7,3); // there are seven integers in this vector, which values are all 3. 


vector::erase()
   iterator erase ( iterator position );
iterator erase ( iterator first, iterator last );
删除元素或一段序列


vector::pop_back()
   void pop_back ( );
   删除最后一个元素



Hot to Copy a Vector to another Vector:

a = b;
Where a and b are vectors.



Vector 不能用new ！！！


New way to initialize a vector:

vector<vector<vector<int>>> dp = vector(k, vector(m, vector(n, -1)));


vector::insert()

   iterator insert ( iterator position, const T& x );

   void insert ( iterator position, size_type n, const T& x );

template <class InputIterator>

void insert ( iterator position, InputIterator first, InputIterator last );

   插入新的元素，

第一个函数，在迭代器指定的位置前插入值为x的元素

第二个函数，在迭代器指定的位置前插入n个值为x的元素

第三个函数，在迭代器指定的位置前插入另外一个容器的一段序列迭代器first到last

若插入新的元素后总得元素个数大于capacity，则重新分配空间

Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequences of numbers, characters etc. They reduce the complexity and execution time of the program.

INT_MIN, INT_MAX are in the library of “climits”



What is the difference between
vector< vector<int> > N; 
and
vector<int> F[N]

In the first case you are creating a dynamic array of dynamic arrays (vector of vectors). The size of each vector could be changed at the run-time and all objects will be allocated on the heap.
In the second case you are creating a fixed-size array of vectors. You have to define N at compile-time, and all vectors will be placed on the stack†, however, each vector will allocate elements on the heap.


### Java <a name="Java"></a>

asd
asdsad

### Python <a name="Python"></a>