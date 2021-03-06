/**
 * @file CalHit.h
 * @brief Class that encapsulate calorimeter hit information
 * @author Omar Moreno, SLAC National Accelerator Laboratory
 */

#ifndef _CALORIMETER_HIT_H_
#define _CALORIMETER_HIT_H_

//----------//
//   ROOT   //
//----------//
#include <TObject.h>

class CalHit : public TObject { 
    
    public:    

        /** Constructor */
        CalHit(); 

        /** Destructor */
        ~CalHit();

        /** Reset the hit object */ 
        void Clear(Option_t* option=""); 

        /**
         * Set the energy of the hit in GeV.
         *
         * @param energy The energy of the hit in GeV. 
         */
        void setEnergy(const double energy){ energy_ = energy; }; 
      
        /** @return The energy of the hit in GeV. */
        double getEnergy() const { return energy_; };

        /**
         * Set the time of the hit in ns. 
         *
         * @param time The time of the hit in ns. 
         */
        void setTime(const double time) { time_ = time; };

        /** @return The time of the hit in ns. */
        double getTime() const { return time_; };

        /**
         * Set the indices of the crystal.
         *
         * @param index_x The index along x
         * @param index_y The index along y
         */
        void setCrystalIndices(int index_x_, int index_y_);       

        /** @return The crystal indices. */ 
        std::vector<int> getCrystalIndices() const { return { index_x_, index_y_ }; }

    private: 
        
        /** The crystal index along x. */
        int index_x_{-9999};

        /** The crystal index along y. */
        int index_y_{-9999};

        /** The energy of the hit in GeV. */ 
        double energy_{-9999};

        /** The time of the hit in ns. */
        double time_{0};
        
        ClassDef(CalHit, 1);
};

#endif
