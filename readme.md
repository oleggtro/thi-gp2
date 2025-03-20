# UFO Simulation Project

This project simulates the flight of various types of Unidentified Flying Objects (UFOs) using C++ and the Boost library for unit testing. The project includes different types of UFOs, such as vertical takeoff and landing (VTOL) UFOs and ballistic UFOs, and provides functionality to calculate flight paths, distances, and angles.

## Requirements
- [Boost C++ Libraries](https://www.boost.org/) (Ensure you have the correct version installed)


## Unit Tests

Unit tests are used to check whether the assignments were completed correctly. They require using the Boost Test Library. The test files are:
- `pa1_utest.cpp`
- `pa2_utest.cpp`
- `pa3_utest.cpp`

I don't have access to `pa4` and `pa5` anymore, but they aren't really required anyways.

### Running the Tests

To run the tests for a specific assignment, you need to modify and execute the `run.sh` script. Here is an example of how you might modify the script:

```sh
# Modify run.sh to specify the test file you want to run
g++ -o test pa1_utest.cpp -lboost_unit_test_framework
./test
```

Then, execute the script:
```sh
./run.sh
```

## License

This project is licensed under GPL v3. See the [LICENSE](LICENSE) file for details.
