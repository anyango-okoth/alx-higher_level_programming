#include <stdio.h>
#include <Python.h>

/**
 * print_python_list - Prints basic information about a Python list.
 * @p: A pointer to a PyObject representing the Python list.
 *
 * Description: This function prints the size of the list and the type of
 * each element in the list.
 */
void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        printf("Error: Invalid PyListObject\n");
        return;
    }

    Py_ssize_t list_size = PyList_Size(p);
    printf("[*] Python list info\n");
    printf("[*] Size of the list: %ld\n", list_size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (Py_ssize_t i = 0; i < list_size; i++) {
        PyObject *item = PyList_GET_ITEM(p, i);
        const char *item_type = item->ob_type->tp_name;
        printf("Element %ld: %s\n", i, item_type);
    }
}

/**
 * print_python_bytes - Prints basic information about a Python bytes object.
 * @p: A pointer to a PyObject representing the Python bytes object.
 *
 * Description: This function prints the size of the bytes object, the first
 * 10 bytes of the object in hexadecimal format, and attempts to print it as
 * a string.
 */
void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("Error: Invalid PyBytesObject\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    Py_ssize_t max_bytes = size > 10 ? 10 : size;

    printf("[.] bytes object info\n");
    printf("size: %ld\n", size);
    printf("trying string: %s\n", PyBytes_AsString(p));

    printf("first %ld bytes: ", max_bytes);
    for (Py_ssize_t i = 0; i < max_bytes; i++) {
        printf("%02hhx", PyBytes_AsString(p)[i]);
        if (i < max_bytes - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

