# Roadmap

                    LOGIC COMPLETE
                         │
              ┌──────────┴──────────┐
              │                     │
           C11 NOW              C++ LATER
              │                     │
        Build the hardware     Question the abstractions
        from gates upward      with OOP
              │                     │
              ▼                     ▼
        "How does it work?"    "How should it be modeled?"


                    Logic Complete
                         │
             ┌───────────┴───────────┐
             │                       │
          Core 0                  Core 1
             │                       │
        ┌────┴────┐             ┌────┴────┐
        │         │             │         │
      Registers  ALU         Registers  ALU
        │         │             │         │
        └────┬────┘             └────┬────┘
             │                       │
             └──────────┬────────────┘
                        │
                     Memory

          LOGIC COMPLETE
                   │
            ┌──────┴──────┐
            │             │
        Hardware      Addressable
        primitives     devices
            │             │
        ROM / RAM      future I/O
        ALU / regs     disk / NIC
        mux / bus      timer / GPIO
        etc.           display / ...

             address
                │
                ▼
        ┌───────────────┐
        │ ADDRESS SPACE │
        │     / MAP     │
        └───────┬───────┘
                │
       ┌────────┼────────┐
       ▼        ▼        ▼
      ROM      RAM      DEVICE
                         │
                    whatever it is


