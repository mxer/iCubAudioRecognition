// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
  * Copyright (C)2017  Department of Neuroscience - University of Lethbridge
  * Author:Matt Tata,  Lukas Grasse, Marko Ilievski
  * email: m.ilievski@uleth.ca, matthew.tata@uleth.ca, francesco.rea@iit.it
  * Permission is granted to copy, distribute, and/or modify this program
  * under the terms of the GNU General Public License, version 2 or any
  * later version published by the Free Software Foundation.
  *
  * A copy of the license can be found at
  * http://www.robotcub.org/icub/license/gpl.txt
  *
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
  * Public License for more details
*/




#ifndef _AUDIO_MEMORY_MAPPER_MODULE_H_
#define _AUDIO_MEMORY_MAPPER_MODULE_H_


#include <yarp/os/RFModule.h>
#include <yarp/os/Network.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/Stamp.h>
#include <yarp/os/NetInt32.h>
#include <yarp/sig/Sound.h>
//#include <iCub/audio/Sound.h>
#include <yarp/sig/Matrix.h>
#include <yarp/sig/Vector.h>

//Memory mapping requirements
#include <sys/mman.h>
#include <fcntl.h>
#include <string>

#include <audioFilteringRateThread.h>

class audioFilteringModule: public yarp::os::RFModule
{
 private:
  std::string moduleName;                  // name of the module
  std::string robotPortName;               // name of robot port
  std::string inputPortName;               // name of the input port for events
  std::string robotName;                   // name of the robot
  std::string configFile;                  // name of the configFile that the resource Finder will seek

  audioFilteringRateThread *rateThread;

 public:
	/**
	* default constructor
	*/
	audioFilteringModule();

	/**
	* destructor
	*/
	~audioFilteringModule();


	bool configure(yarp::os::ResourceFinder &rf);
	double getPeriod();
	bool updateModule();
	bool interruptModule();
	bool close();


private:



};

#endif