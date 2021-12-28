## Useful attributes

* [[nodiscard(<reason?>)]]: We can use this attribute in a function to say that the return result can't be ignored.
* [[maybe_unused]]: We can use this in function parameters to prevent warnings of not used variables.
* [[noreturn]]: We can use this in function declarations to say that the function doesn't return the control to the caller. This means that it executes undefitely until either an exception is thrown or the program/thread is terminated.
* [[deprecated(<reason?>)]]: We can use this in function declarations to say that the function should not be used anymore. An optional reason string can be provided, giving for example instructions on new alternatives to using it.
* 