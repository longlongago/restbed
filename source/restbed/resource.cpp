/*
 * Site: restbed.corvusoft.co.uk
 * Author: Ben Crowhurst
 *
 * Copyright (c) 2013 Restbed Core Development Team and Community Contributors
 *
 * This file is part of Restbed.
 *
 * Restbed is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Restbed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with Restbed.  If not, see <http://www.gnu.org/licenses/>.
 */

//System Includes

//Project Includes
#include "restbed/method.h"
#include "restbed/request.h"
#include "restbed/response.h"
#include "restbed/resource.h"
#include "restbed/detail/resource_impl.h"

//External Includes

//System Namespaces
using std::map;
using std::vector;
using std::string;
using std::function;

//Project Namespaces
using restbed::detail::ResourceImpl;

//External Namespaces

namespace restbed
{
    Resource::Resource( void ) : m_pimpl( new ResourceImpl )
    {
        //n/a
    }
    
    Resource::Resource( const Resource& original ) : m_pimpl( new ResourceImpl( *original.m_pimpl ) )
    {
        //n/a
    }
    
    Resource::~Resource( void )
    {
        //n/a
    }

    string Resource::get_path( void ) const
    {
        return m_pimpl->get_path( );
    }
        
    vector< string > Resource::get_path_filters( void ) const
    {
        return m_pimpl->get_path_filters( );
    }

    string Resource::get_header_filter( const string& name ) const
    {
        return m_pimpl->get_header_filter( name );
    }

    map< string, string > Resource::get_header_filters( void ) const
    {
        return m_pimpl->get_header_filters( );
    }

    function< Response ( const Request& ) > Resource::get_method_handler( const Method& method ) const
    {
        return m_pimpl->get_method_handler( method );
    }

    map< string, function< Response ( const Request& ) > >  Resource::get_method_handlers( void ) const
    {
        return m_pimpl->get_method_handlers( );
    }

    void Resource::set_path( const string& value )
    {
        m_pimpl->set_path( value );
    }

    void Resource::set_header_filter( const string& name, const string& value )
    {
        m_pimpl->set_header_filter( name, value );
    }

    void Resource::set_method_handler( const Method& verb, const function< Response ( const Request& ) >& callback )
    {
        m_pimpl->set_method_handler( verb, callback );
    }

    bool Resource::operator <( const Resource& rhs ) const
    {
        return *m_pimpl < *rhs.m_pimpl;
    }
    
    bool Resource::operator >( const Resource& rhs ) const
    {
        return *m_pimpl > *rhs.m_pimpl;
    }
    
    bool Resource::operator ==( const Resource& rhs ) const
    {
        return *m_pimpl == *rhs.m_pimpl;
    }
    
    bool Resource::operator !=( const Resource& rhs ) const
    {
        return *m_pimpl != *rhs.m_pimpl;
    }

    Resource& Resource::operator =( const Resource& rhs )
    {
        *m_pimpl = *rhs.m_pimpl;

        return *this;
    }
}
