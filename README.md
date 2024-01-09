# shutdown-scheduler
a little shutdown scheduler to power off a pc especially for Windows, with a timeout or a given hour.

# use
    // -to = timeout
    // -h = hour

    .\shutdown-scheduler.exe <-h|-to> <days> <time>

    example
    .\shutdown-scheduler.exe -h 2 18:00:00
    //your pc will be shutdown in two days at 18h.

    .\shutdown-scheduler.exe -to 0 00:10:00
    //your pc will be shutdown today in ten minutes.