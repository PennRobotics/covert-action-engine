PLOT.TXT contains the chief's briefing and debriefing text:

(up to 5 pages)

    String ID: *PL<mission set ID><crime nr><special>
    
    mission set ID is two bytes
    crime number is one byte
    on success, read special 0 to 4
    on failure, read special 5 to 9
    
    on start following fail, read special A to F
    on start of mission set, *PL<mission set ID>9<0 to 5>
