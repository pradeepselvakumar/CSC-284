---

### **Assignment: Chatroom Server and Client in C++**

####  **Objective:**
Implement a simple multi-user chatroom system using sockets in C++. You are to write both the **Chatroom Server** and **Chatroom Client** applications. The system should allow users to create and join chatrooms, and communicate with others in the same room. A user may only belong to **one chatroom at a time**.

---

### **Part 1: Chatroom Client**

#### Requirements:
- The client must accept **IP address** and **port number** as **command-line arguments**.
- After connecting to the server, the client must:
  - Allow the user to input chat commands or messages.
  - Support the same commands defined in the server (`CREATE_ROOM`, `JOIN_ROOM`, etc.).
  - Display messages received from the server in real time.
- The client should also allow users to type and send freeform messages to others in the room.


---

### **Part 2: Chatroom Server**

#### Requirements:
- The server must accept a **port number** as input at startup.
- The server must:
  - Handle **multiple clients concurrently** using threads.
  - Maintain a list of available **chatrooms**.
  - Support the following commands sent by clients:
    - `CREATE_ROOM <room_name>`: Create a new room.
    - `JOIN_ROOM <room_name>`: Join an existing room.
    - `LIST_ROOMS`: List all available chatrooms.
    - `EXIT`: Disconnect from the chatroom.
- The server should:
  - Maintain room membership.
  - Only deliver messages to users within the same room.
  - Notify users when others join or leave the room.

---

### **Bonus (Optional):**
- Allow the client to specify a **username** when connecting. If not specified, default to an anonymous ID.
- The server should use the username when displaying messages or notifications.

---

### **Hints:**
- Use `std::thread` to handle multiple clients on the server.
- Use `std::mutex` to protect shared data structures like the room list and client registry.
- Use a **TCP socket** for reliable communication.
- Test using multiple terminal windows or computers on the same network.

---

###  **Deliverables:**
1. `chatroom_server.cpp` – Your server implementation.
2. `chatroom_client.cpp` – Your client implementation.
3. A short README with:
   - How to compile and run your applications.
   - Any known issues or assumptions.
