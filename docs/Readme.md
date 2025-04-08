# TEM - Tiny Extension Manager
![Logo](./logo1.webp)
### Features
- Fast create extension system on shared libraries
- Easy and tiny API
- Few depends(std c lib / +APIMacro, dlfcn.h / windows.h)

**APIMacro** is a header that can override std c lib and adds a couple of features, you can remove it after building, but it's also likely to be needed when developing the extensions themselves if you used it in the shell for the extensions.
