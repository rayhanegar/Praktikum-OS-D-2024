function mutexRun()
{
  gcc -pthread mutex.c -o mutex;
  mkdir output-mutex;
  for((i=0;i<10;i++));
  do
    ./mutex > output-mutex/mutex-run$i.out;
  done
}

function nonMutexRun()
{
  gcc -pthread non-mutex.c -o non-mutex;
  mkdir output-non-mutex;
  for((i=0;i<10;i++));
  do
    ./non-mutex > output-non-mutex/non-mutex-run$i.out;
  done
}

function join()
{
  gcc -pthread join.c -o join;
  mkdir output-join;
  for((i=0;i<10;i++));
  do
    ./join > output-join/join-run$i.out;
  done
}

while true
do
  echo "1. execute mutex.c"
  echo "2. execute non-mutex.c"
  echo "3. execute join.c"
  echo "4. exit"
  echo -n "choose: "
  read VAR
  case $VAR in
    1) mutexRun
    ;;
    2) nonMutexRun
    ;;
    3) join
    ;;
    4) break
    ;;
    *) echo "pilih: "
    ;;
  esac
done


