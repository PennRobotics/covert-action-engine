#pragma once

class MainChar {
public:
    MainChar() = default;
    MainChar(std::string csign, int rank, Aptitude co, Aptitude dr, Aptitude cr, Aptitude el) :
            callsign{std::move(csign)},
            rank{rank},
            apt_combat{co},
            apt_driving{dr},
            apt_crypto{cr},
            apt_elec{el}
    {}
    ~MainChar() = default;
    MainChar(const MainChar&) = delete;
    MainChar& operator=(const MainChar&) = delete;

    void setCallsign(std::string s)  { this->callsign = s; }
    void setRank(int rank)  { this->rank = rank; }
    void setSkillLevels(Aptitude co, Aptitude dr, Aptitude cr, Aptitude el) {
        this->apt_combat = co;
        this->apt_driving = dr;
        this->apt_crypto = cr;
        this->apt_elec = el;
    }

    std::string getCallsign()  { return this->callsign; }
    int getRank()  { return this->rank; }
    Aptitude getCombatAptitude()  { return apt_combat; }
    Aptitude getDrivingAptitude()  { return apt_driving; }
    Aptitude getCryptoAptitude()  { return apt_crypto; }
    Aptitude getElecAptitude()  { return apt_elec; }

    std::string callsign;

    int rank {99};
    Aptitude apt_combat {Aptitude::Average};
    Aptitude apt_driving {Aptitude::Average};
    Aptitude apt_crypto {Aptitude::Average};
    Aptitude apt_elec {Aptitude::Average};
};
