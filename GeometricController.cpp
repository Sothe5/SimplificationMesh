///////////////////////////////////////////////////
//
//	Hamish Carr
//	February, 2019
//
//	------------------------
//	GeometricController.cpp
//	------------------------
//	
///////////////////////////////////////////////////

#include "GeometricController.h"
#include <iostream>
// constructor
GeometricController::GeometricController(GeometricSurfaceDirectedEdge *Surface, GeometricWindow *Window)
	: surface(Surface), window(Window)
	{ // constructor
	QObject::connect(	window->smoothnessSlider,	SIGNAL(valueChanged(int)), 
						this,						SLOT(smoothnessSliderChanged(int)));
	} // constructor

// slot for responding to slider changes
void GeometricController::smoothnessSliderChanged(int value)
	{ // smoothnessSliderChanged()
		
		float percentage = ( 100 - (float)value)/100.0;
		unsigned int until = percentage * surface->position.size();
		 //printf("percentage %f\n", percentage);
		printf("until %d\n", until);
		
		while (surface->myQueue.size() > until)	// remove vertices until it reached a percentage of the mesh size
		{

			std::pop_heap(surface->myQueue.begin(), surface->myQueue.end());
			Holder vertexToRemove = surface->myQueue.back();
			std::set<indexType> neighbours = surface->getNeighbours(vertexToRemove.vertexId);	// compute the neighbours of the removed vertex

			surface->DeleteVertex(vertexToRemove.vertexId);
			surface->myQueue.pop_back();

			
			for(auto b : neighbours)	// for each neighbours search which are those element in the queue and update their 1RingSize
			{
				for(int j = 0; j < surface->myQueue.size() ; j++)
				{
					if(surface->myQueue[j].vertexId == b)
					{
						surface->myQueue[j].sizeRing = surface->get1RingSize(surface->myQueue[j].vertexId);
					}
				}
			}
			std::make_heap(surface->myQueue.begin(), surface->myQueue.end());	// order again	
		}

		window->ResetInterfaceElements();
	} // smoothnessSliderChanged()
