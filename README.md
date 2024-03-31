# minishell2

## Module: B-PSU-200 (Grade: N/A)

## Project Description
 minishell1 + 1

### USAGE
 ./minishell2
# Result: 100%
<details>
<summary>Click to expand test results</summary>

### 01 - basic tests (100% Passed)
| Test | Status |
| --- | --- |
| Empty | PASSED |
| SegFault without core dump | PASSED |
| Simple exec | PASSED |
| run simple commands | PASSED |
| wrong simple command | PASSED |

### 02 - path handling (100% Passed)
| Test | Status |
| --- | --- |
| PATH 1 | PASSED |
| PATH 2 | PASSED |
| PATH 3 | PASSED |
| PATH 4 | PASSED |
| PATH 5 | PASSED |

### 02 - path handling - eval (100% Passed)
| Test | Status |
| --- | --- |
| PATH 1 | PASSED |
| PATH 2 | PASSED |
| PATH 3 | PASSED |
| PATH 4 | PASSED |
| PATH 5 | PASSED |

### 03 - setenv and unsetenv (100% Passed)
| Test | Status |
| --- | --- |
| setenv and unsetenv | PASSED |
| setenv and unsetenv with special values | PASSED |

### 03 - setenv and unsetenv - eval (100% Passed)
| Test | Status |
| --- | --- |
| setenv and unsetenv | PASSED |
| setenv and unsetenv with special values | PASSED |

### 04 - builtin cd (100% Passed)
| Test | Status |
| --- | --- |
| cd | PASSED |
| cd and error messages | PASSED |
| cd- | PASSED |

### 04 - builtin cd - eval (100% Passed)
| Test | Status |
| --- | --- |
| cd | PASSED |
| cd and error messages | PASSED |
| cd- | PASSED |

### 05 - line formatting (space and tabs) (100% Passed)
| Test | Status |
| --- | --- |
| space 1 | PASSED |
| space 2 | PASSED |
| space 3 | PASSED |
| space 4 | PASSED |
| space and tab | PASSED |
| tab 1 | PASSED |
| tab 2 | PASSED |
| tab 3 | PASSED |

### 05 - line formatting (space and tabs) - eval (100% Passed)
| Test | Status |
| --- | --- |
| space 1 | PASSED |
| space 2 | PASSED |
| space 3 | PASSED |
| space 4 | PASSED |
| space and tab | PASSED |
| tab 1 | PASSED |
| tab 2 | PASSED |
| tab 3 | PASSED |

### 06 - error handling (100% Passed)
| Test | Status |
| --- | --- |
| Bin not compatible | PASSED |
| SegFault with core dump | PASSED |
| exec a directory | PASSED |

### 06 - error handling - eval (100% Passed)
| Test | Status |
| --- | --- |
| Bin not compatible | PASSED |
| SegFault without core dump | PASSED |
| exec a directory | PASSED |

### 07 - separator (100% Passed)
| Test | Status |
| --- | --- |
| advanced separator 1 | PASSED |
| advanced separator 2 | PASSED |
| complex separator | PASSED |
| multiple separator | PASSED |
| separator basic | PASSED |

### 08 - simple pipe (100% Passed)
| Test | Status |
| --- | --- |
| pipe with big input | PASSED |
| simple pipe 1 | PASSED |
| simple pipe 2 | PASSED |
| simple pipe 3 | PASSED |

### 09 - simple redirections (100% Passed)
| Test | Status |
| --- | --- |
| output double-redirect | PASSED |
| output redirect | PASSED |

### 10 - advanced pipe (100% Passed)
| Test | Status |
| --- | --- |
| Multipipe and Error | PASSED |
| Pipe with builtin | PASSED |
| error and pipe | PASSED |
| multipipe | PASSED |
| multipipe and FDMAX | PASSED |
| only a pipe | PASSED |
| pipe and error | PASSED |

### 11 - advanced redirections (100% Passed)
| Test | Status |
| --- | --- |
| redirect on bin and big files | PASSED |

### 12 - advanced manipulations (100% Passed)
| Test | Status |
| --- | --- |
| Long command line with multiple redirect and pipe | PASSED |
| empty seperator | PASSED |
| redirect output on input | PASSED |
| running mysh inside mysh | PASSED |

</details>

## Tests
multiples executable in the tests folder to run in the shell to see the error messages

