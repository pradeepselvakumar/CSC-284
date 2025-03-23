Requirements

    Templated Class (InventoryProcessor<T>)
        Stores and processes inventory data of type T.
        Provides functions for I/O operations using JSON format.
        Uses template specialization for complex data structures (std::string, double, int).

    JSON Parsing
        Use the nlohmann/json library for parsing JSON files.
        Read and write nested JSON structures.

    File Handling
        Read from an input JSON file (inventory.json).
        Write processed results to an output JSON file (summary.json).

    Main Program
        Ask the user for an input and output filename.
        Process inventory data dynamically.
        Use InventoryProcessor<T> to handle different data attributes.


### **Guidelines for Implementation**  

1. **Create a `Product` Class**  
    - This class represents individual products in the inventory.  
    - Include fields for:  
      - `name` (string)  
      - `category` (string)  
      - `quantity` (int)  
      - `price` (double)  
    - Implement a constructor for easy initialization.  
    - Optionally, add getters or utility methods if needed.  

2. **Create a Templated `InventoryProcessor<T>` Class**  
    - While this assignment uses `Product` as the data type, templating the class allows flexibility to read and process different data types in the future.  
    - This makes the program adaptable to other JSON files containing different structures (e.g., employee data, sales reports, etc.).  
    - Implement the following methods:  
      - `readFromFile(const std::string& filename)` - Read JSON data into a vector of `T` objects.  
      - `process()` - Perform data analysis and generate useful results (e.g., sum, average, or summaries depending on the type).  
      - `writeToFile(const std::string& filename)` - Write results to a JSON file.  

3. **Template Specialization**  
    - Use template specialization for `InventoryProcessor<Product>` to handle product-specific operations.  
    - Calculate the **total stock value** and identify the **most expensive product**.  
    - Generate a **category summary** with aggregated information.

4. **File Handling**  
    - Use `std::filesystem` to check file existence.  
    - Provide error messages if the file cannot be opened or read.  

5. **JSON Parsing**  
    - Use the [`nlohmann/json`](https://github.com/nlohmann/json) library to parse and write JSON data.  

6. **Main Function**  
    - Instantiate `InventoryProcessor<Product>` to read, process, and write results.  
    - Allow the program to handle additional data types in the future by changing the class instantiation to `InventoryProcessor<OtherType>` if needed.  

