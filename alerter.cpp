#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if(celcius > 250)
        return 500;
    // Return 200 for ok
    // Return 500 for not-ok
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

void testAlertFailureCount() {

    alertFailureCount = 0;
    
    // Test cases
    alertInCelcius(200); 
    std::cout << "AlertFailureCount = " << alertFailureCount << std::endl;
    assert(alertFailureCount == 1);
    
    alertInCelcius(300); 
    std::cout << "AlertFailureCount = " << alertFailureCount << std::endl;
    assert(alertFailureCount == 2);
    
    alertInCelcius(150);   
    std::cout << "AlertFailureCount = " << alertFailureCount << std::endl;
    assert(alertFailureCount == 2); 

    std::cout << "All tests passed successfully!\n";
}


int main() {    
    testAlertFailureCount();

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
