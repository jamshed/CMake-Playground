# Set the project name and the language. By default, the languages
# are C and C++
project(Hello LANGUAGES NONE)

# Set a variable called `GREETING` with a value "Hello, CMake!".
set(GREETING "Hello, CMake!")

# This prints a string "GREETING".
message(GREETING)

# Print the value of the variable `GREETING` by dereferencing it.
message(${GREETING})


set(VERB Hello)
set(NOUN CMake)
set(GREETING "${VERB}, ${NOUN}!")

message (${GREETING})
