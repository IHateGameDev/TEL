# Contributing to the Project

Thank you for considering contributing to our project! We appreciate your help.

## How to Contribute

1. Fork the repository.
2. Clone the repository: `git clone https://github.com/YourName/TEM.git`.
3. Create a new branch: `git checkout -b branch-name`.
4. Make your changes and commit them: `git add . && git commit -m "Add: feature"`.
5. Push changes in your repository: `git push origin branch-name`.
6. Pull request.

## Coding Standards

- Use **2** spaces for indentation.
- Name variables in `camelCase`.
- Use `API` from [APIMacros](https://github.com/IHateGameDev/APIMacros)/api.h before public functions.
- Use library prefix in public functions.
- `prefixActionName` naming for init / create / new functions: `API info* libNewInfo()`.
- `prefixNameAction` naming for other functions: `API void libInfoPushInt()` but if the action is more important you can use `prefixActionStruct` or `prefixAction`..

## Commit standards

- Clear and understandable name of the added / deleted / changed / fixed
- Use [actions](#actionsTable) in name (optional but desirable)

<a name="actionsTable">Actions table: </a>

| Action | Description (Use if) | Example |
| ------------------- | ----------------------------------------------------------------------------------- | ------------------- |
| Add:                | Add new feature(s) or file(s)                                                       | "Add: tests/load.c" |
| Remove:             | Remove feature(s) or file(s)				                                        | "Remove: hdrtest"   |
| Change / Review:    | Change feature(s) or file(s), review code and solutions                             | "Review: project structure" |
| Fix / HotFix:       | Apply fix or hotfix to feature(s) or file(s)                                        | "Fix: actions table in CONTRIBUTING.md" |
| Preparation: (List) | "Preparation" use on "preparation/X.X.X" branch for releases. List is other actions | "Preparation: Add: doc for queue.h" |
| Stable:             | Stable version for main branch                                                      | "Stable: v0.1.0" |

## Test your changes

Before submitting a pull request, please test your changes!

## Reporting Issues

If you find a bug, please create a new issue in the repository with a description of the problem.

## License

This project is licensed under the MIT License. Please see the [LICENSE](../License) file for more information.

## Contact Information

If you have any questions, feel free to reach out to us at <ihategamedev@proton.me> or [Telegram](https://t.me/IHateGameDev).
