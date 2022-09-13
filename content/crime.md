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
    ss ss ss ss ss ss dd tt bb xx vv vv

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

- 02 Sent message (paired with 3)
- 03 Received message (paired with 2)
- 08 Met with (paired with 9)
- 09 Was met by (paired with 8)
- 20 Crime

### Blank event entry (qty. 1)

    FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    00 00 00 00 00 00 00 00 00 00 00 00

### Object entry

    oo oo oo oo oo oo oo oo oo oo oo oo oo oo oo oo
    ii FF

- ii = Icon ID

#### Icons

- 00 - Processed drugs
- 01 - Sniper rifle / Weapons
- 02 - Raw drugs
- 03 - Chemicals / Supplies
- 04 - Explosives
- 05 - Alarm Bypass / Product
- 06 - Photographs
- 07 - Hostage / Pilot / Escapee
- 08 - Bomb
- 09 - Payoff / $1,000,000 / Gold coin
- 0A - Photographs
- 0B - Camera
- 0C - Blueprints / Mission plans
- 0D - Stolen goods / Jeep / Sample item / Forgery / Equipment
- 0E - Passwords

## TODO

- How is timing determined?
- Minor vs major crimes?
- What are the unknown bytes? (`??`)

