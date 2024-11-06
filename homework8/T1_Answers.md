What is the difference between struct and class?
- The main difference is the default access level for members. 
  In a struct members are public by default but in a class they are private by default.

Why do we need our class to be derived from the TObject?
- TObject provides integration with ROOT's object management system. It also provides functionality such as garbage collection, object streaming and GUI interactions. 
  Furthermore using ClassDef and ClassImp macros enable RTTi making it easier to use the class in ROOT scripts.
