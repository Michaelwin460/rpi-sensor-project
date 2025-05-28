#!/bin/bash
./build.sh
./test.sh

if [ $? -eq 0 ]; then
  echo "Tests passed, ready for release!"
  # הוספת צעדים לדיפלוא או יצירת ארכיב
  ./clean.sh
else
  echo "Tests failed, release aborted."
  exit 1
fi

