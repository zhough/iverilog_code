int a = 10;
int b = 20;
int sum;

int add(int x, int y) {
    return x + y;
}

void main(void) {
    sum = add(a, b);

    for (int i = 0; i < 100; i++) {
        sum += i;
    }

    int arr[4] = {1,2,3,4};
    sum += arr[0] + arr[3];

    while(1);
}