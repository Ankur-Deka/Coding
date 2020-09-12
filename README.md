## CPP
### Pointers vs References
References are essentially pointers in disguise. Internally the same thing happens, it's just easier to write and read the code.

```
int a;
int& ref = a; // must be initialized to point to an existing variable
int& ref; 	  // is invalid
```

### Structures vs Classes
Just one technical difference, default visibility of class is private while it is public for struct. Struct exists for backward compatibility with C. Generally we use structures to store only data and don't add function and inheritence.

### To or not to use new
Allocating memory isn't really a difference, both of the following allocate memory
```
int* a = new int(5);
int a = 5;
```

When we use `new`, the memory isn't cleared until we call delete. So it's useful when we want to return a pointer to a new variable as shown below:
```
int* get_num()
{
	int* a = new int(5);
	*a *= 100;
	return a;
}

int main()
{
	int* a = get_num();
	cout<<*a;
	delete a;
}
```

### [Cherno's C++ playlist](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&ab_channel=TheCherno)
Watched:
1. Till Classes vs structs (upto 19)
1. Strings (32)
1. `new` (39)