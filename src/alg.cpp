// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        k +=1;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
  int i = len - 1, k = 0;
  while (arr[i] > value) {
    i--;
  }
  for (i; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if ((arr[i] + arr[j]) == value) {
        k += 1;
      }
    }
  }
  return k;
}

int countPairs3(int *arr, int len, int value) {
  int n = len - 1, k = 0, x = 0, f = 0, v = 0;
  if (value % 2 == 0) {
    v = value / 2;
    f = cbinsearch(arr, len, (value / 2));
  } else
    v = (value + 1) / 2;
  while (arr[n] >= v) {
    n--;
  }
  k += f * (f - 1) / 2;
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      if ((value - arr[i]) == arr[i]) {
        x = cbinsearch(arr, len, (value - arr[i])) - 1;
      } else
        x = cbinsearch(arr, len, (value - arr[i]));
      k += x;
    } else {
      if (arr[i] == arr[i-1])
        k += x;
      else {
        if ((value - arr[i]) == arr[i]) {
          x = cbinsearch(arr, len, (value - arr[i])) - 1;
        } else
          x = cbinsearch(arr, len, (value - arr[i]));
        k += x;
      }
    }
  }    
  return k;
}

int cbinsearch(int *arr, int size, int value) {
  int i = 0, j = size - 1, k = 0;
  while (i < j) {
    int mid = i + (j - i) / 2;
    if (arr[mid] == value) {
      k +=1;
      int h = 1;
      while (arr[mid - h] == value) {
        k +=1;
        h +=1;
      }
      h = 1;
      while (arr[mid + h] == value) {
        k += 1;
        h += 1;
      }
      return k;
    } else {
      if (arr[mid] > value)
        j = mid;
      else
        i = mid + 1;
    }
    if (j == i) {
      if (arr[i] == value) {
        k +=1;
        return k;
      }
    }
  }
  return 0;
}
