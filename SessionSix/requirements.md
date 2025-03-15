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

    Guidelines for Implementation

    Create a templated class (`InventoryProcessor<T>) that:
        Reads inventory data from JSON.
        Computes total stock value.
        Identifies the most expensive product.
        Summarizes data by category.

    Use template specialization for handling different data types:
        Numerical operations for quantity and price.
        String operations for product names and categories.

    Implement JSON file parsing using nlohmann/json