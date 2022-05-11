import { Body, Controller, Post } from '@nestjs/common';
import { DataService } from './data.service';
import { LogDto } from './dto';

@Controller('data')
export class DataController {
    constructor(private dataService: DataService){};
    @Post("getLog")
    getLog(@Body() dto: LogDto){
        return this.dataService.getESPLog(dto);
    }
}
