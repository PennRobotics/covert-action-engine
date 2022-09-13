## Crime file format

### Header

    pp 00 ee 00

- pp = # Participants
- ee = # Events + 1

### Participant entry

    FF FF ?? 00 nn nn nn nn nn nn nn nn nn nn nn nn
    nn nn nn nn nn nn nn nn nn nn nn nn nn nn nn nn
    nn nn nn nn ?? ?? mm ?? 00 00 ?? 00 rr 00 ?? 00

- nn = name of role (32 bytes)
- mm = mastermind if 1
- rr = participant rank

### Event entry (qty. ee)

    ll 00 00 00 cc 00 ss ss ss ss ss ss ss ss ss ss
    ss ss ss ss ss ss ss ss ss ss ss ss ss ss ss ss
    ss ss ss ss 00 dd tt bb xx vv 00 00

_These offsets need to be double-checked!_

- ll = Link to person conducting entry
- cc = Case event/message ID
- ss = Event or message statement/description
- dd = Event destination/target/recipient
- tt = Type
- bb = Bitmask for received item (bit # = item #)
- xx = Bitmask for destroyed item
- vv = Value of event. Multiply by 40 to get score.

#### Types

- 2. Sent message (paired with 3)
- 3. Received message (paired with 2)
- 8. Met with (paired with 9)
- 9. Was met by (paired with 8)
- 20. Crime  [20h or decimal 20?]

### Blank event entry (qty. 1)

    FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00

### Object entry

    oo oo oo oo oo oo oo oo oo oo oo oo oo oo oo oo
    ii FF

- ii = Icon ID

#### Icons

- 0. Processed drugs
- 1. Sniper rifle / Weapons
- 2. Raw drugs
- 3. Chemicals / Supplies
- 4. Explosives
- 5. Alarm Bypass / Product
- 6. Photographs
- 7. Hostage / Pilot / Escapee
- 8. Bomb
- 9. Payoff / $1,000,000 / Gold coin
- 10. Photographs
- 11. Camera
- 12. Blueprints / Mission plans
- 13. Stolen goods / Jeep / Sample item / Forgery / Equipment
- 14. Passwords

## TODO

- How is timing determined?
- Minor vs major crimes?
- What are the unknown bytes? (`??`)

