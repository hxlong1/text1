#include <stdio.h>  
  
// 注射器型号数组  
double syringeVolumes[] = {1.0, 3.0, 5.0};  
int numSyringeTypes = sizeof(syringeVolumes) / sizeof(syringeVolumes[0]);  
  
// 注射剂量比例数组（相对于注射器容量）  
double doseRatios[] = {0.8, 2.0/3.0, 1.0, 4.0/5.0, 1.0};  
// 注射器容量的比例。  
int numDoseTypes = sizeof(doseRatios) / sizeof(doseRatios[0]);  
  
// 注射次数范围  
const int minInjections = 10;  
const int maxInjections = 180;  
const int injectionIncrement = 10;  
  
// 计算并打印所有可能的组合和单次注射剂量  
void calculateInjections() {  
    for (int syringeIndex = 0; syringeIndex < numSyringeTypes; ++syringeIndex) {  
        double syringeVolume = syringeVolumes[syringeIndex];  
        for (int doseIndex = 0; doseIndex < numDoseTypes; ++doseIndex) {  
            double actualDoseVolume = syringeVolume * doseRatios[doseIndex];  
            for (int injectionCount = minInjections; injectionCount <= maxInjections; injectionCount += injectionIncrement) {  
                double singleInjectionVolume = actualDoseVolume / injectionCount;  
                printf("Syringe Volume: %.1f ml, Dose Ratio: %.2f, Injection Count: %d, Single Injection Volume: %.4f ml\n",  
                       syringeVolume, doseRatios[doseIndex], injectionCount, singleInjectionVolume);  
            }  
        }  
    }  
}  
  
int main() {  
    calculateInjections(); // 调用函数以计算和打印所有可能的组合和单次注射剂量  
    return 0;  
}
