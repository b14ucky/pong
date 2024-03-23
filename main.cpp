#include "App.h"

#include "MatrixTest.h"

int main()
{
    App app;
    MatrixTest MatrixTest;
    MatrixTest.setup();
    MatrixTest.run();
    app.run();
}