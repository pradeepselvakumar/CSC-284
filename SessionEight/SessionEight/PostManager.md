### **C++ API Interaction Exercise**

**Objective:**  
Create a command-line C++ program that connects to the API at [https://jsonplaceholder.typicode.com/](https://jsonplaceholder.typicode.com/) to perform basic CRUD operations using HTTP requests.

---

## **Part 1: Setting Up a New Project in Visual Studio**

1. Create a new project named PostManager 

2. **Install Libraries Using vcpkg**
   - Using a terminal, clone and bootstrap vcpkg:
     ```bash
     > git clone https://github.com/microsoft/vcpkg.git
     > cd vcpkg
     > .\bootstrap-vcpkg.bat
     ```
   - Install `cpr`:
     ```bash
     vcpkg install cpr
     ```
   - Integrate with Visual Studio:
     ```bash
     .\vcpkg integrate install
     ```

4. **Configure Your Project**
   - Right-click your project in Solution Explorer → **Properties**.
   - Go to **C/C++** → **General** → **Additional Include Directories** and add the vcpkg include path (e.g., `C:\vcpkg\installed\x64-windows\include`).
   - Go to **Linker** → **General** → **Additional Library Directories** and add the vcpkg lib path (e.g., `C:\vcpkg\installed\x64-windows\lib`).
   - Go to **Linker** → **Input** → **Additional Dependencies** and add `cpr.lib` or `libcurl.lib`.

---
## **Part 3: Exercise Tasks**

Perform the following actions using the API:

1. **Read a Post**: Retrieve a specific post using `GET /posts/{id}`.
2. **Add a New Post**: Create a post using `POST /posts`.
3. **Update a Post**: Modify an existing post using `PUT /posts/{id}`.
4. **Delete a Post**: Remove a post using `DELETE /posts/{id}`.

---

## **Part 4: Example CLI Workflow**

```plaintext
Select an action:
1. Read a Post
2. Add a New Post
3. Update a Post
4. Delete a Post
5. Exit
Choice: 1
Enter Post ID: 5

Fetching Post ID 5...
Title: Lorem Ipsum
Body: Dolor sit amet, consectetur adipiscing elit.
```

---

## **Part 5: Example API Calls using `cpr`**
Note: You will need to add the following include in order to use cpr:

`#include <cpr/cpr.h>`

- **Read a Post:**
  ```cpp
  auto response = cpr::Get(cpr::Url{"https://jsonplaceholder.typicode.com/posts/1"});
  std::cout << response.text << std::endl;
  ```

- **Add a Post:**
  ```cpp
  auto response = cpr::Post(
      cpr::Url{"https://jsonplaceholder.typicode.com/posts"},
      cpr::Payload{{"title", "Test Post"}, {"body", "This is a test."}, {"userId", "1"}});
  std::cout << response.text << std::endl;
  ```

- **Update a Post:**
  ```cpp
  auto response = cpr::Put(
      cpr::Url{"https://jsonplaceholder.typicode.com/posts/1"},
      cpr::Payload{{"title", "Updated Title"}, {"body", "Updated Body"}});
  std::cout << response.text << std::endl;
  ```

- **Delete a Post:**
  ```cpp
  auto response = cpr::Delete(cpr::Url{"https://jsonplaceholder.typicode.com/posts/1"});
  std::cout << response.status_code << " Post deleted." << std::endl;
  ```

---

