# Preemptive Scheduling Demo

This project shows how to implement a preemptive scheduling program mainly, and it uses assembly language to save and store registers and the stack for the current thread to implement preemptive scheduling. The program is for demo purposes and can only build on Apple Silicon.

## Preemptive Design

According to the topic, there are three parts main, scheduler, and worker to form the preemptive scheduling program.

1. Main: bootstrap and teardown of the whole program
2. Scheduler: implement the preemptive scheduling policy and schedule the worker by timeslice
3. Worker: the entity scheduled by the scheduler

```
                                                                ┌ ─ ─ ─ ─ ─ ─ 
                                                                  ┌────────┐ │
                                                                │ │ Task1  │  
                          ┌──────────────┐                        └────────┘ │
                          │              │     Manage           │ ┌────────┐  
                    ┌────▶│  Scheduler   │─────────────────────▶  │ Task2  │ │
                    │     │              │                      │ └────────┘  
┌──────────────┐    │     └──────────────┘                        ┌────────┐ │
│              │    │                                           │ │ Task3  │  
│     Main     │────┤                                             └────────┘ │
│              │    │                                           └ ─ ─ ─ ─ ─ ─ 
└──────────────┘    │     ┌──────────────┐                                    
                    │     │              │      Run         ┌────────┐        
                    └────▶│    Worker    │─────────────────▶│ Task4  │        
                          │              │                  └────────┘        
                          └──────────────┘                                    
```



